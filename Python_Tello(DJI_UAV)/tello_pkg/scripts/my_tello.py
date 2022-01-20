#!/usr/bin/env python
#coding:utf-8
import socket
import threading
import time
import numpy as np

class Tello:
    """Wrapper class to streract with the Tello drone."""

    def __init__(self, local_ip, local_port, imperial=False, command_timeout=.3, tello_ip='192.168.10.1',
                 tello_port=8889):
        """
        Binds to the local IP/port and puts the Tello stro command mode.
        :param local_ip (str): Local IP address to bind.
        :param local_port (str): Local port to bind.
        :param imperial (bool): If True, speed is MPH and distance is feet.
                             If False, speed is KPH and distance is meters.
        :param command_timeout (str|float): Number of seconds to wait for a response to a command.
        :param tello_ip (str): Tello IP.
        :param tello_port (str): Tello port.


        """

        self.abort_flag = False
        self.command_timeout = command_timeout
        self.imperial = imperial
        self.response = None  
        self.frame = None  # numpy array BGR -- current camera output frame
        self.is_freeze = False  # freeze current camera output
        self.last_frame = None
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # socket for sending cmd
        self.socket_video = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # socket for receiving video stream
        self.tello_address = (tello_ip, tello_port)
        self.local_video_port = 11111  # port for receiving video stream
        self.last_height = 0
        self.socket.bind((local_ip, local_port))

        # thread for receiving cmd ack
        self.receive_thread = threading.Thread(target=self._receive_thread)
        self.receive_thread.daemon = True

        self.receive_thread.start()

        self.socket.sendto(b'command', self.tello_address)
        print ('sent: command')
        # 默认发送command 开启 sdk 调试模式

    def __del__(self):
        """Closes the local socket."""

        self.socket.close()
        self.socket_video.close()
    
    def read(self):
        """Return the last frame from camera."""
        if self.is_freeze:
            return self.last_frame
        else:
            return self.frame


    def _receive_thread(self):
        """Listen to responses from the Tello.
        Runs as a thread, sets self.response to whatever the Tello last returned.
        """
        while True:
            try:
                self.response, ip = self.socket.recvfrom(3000)
                #print(self.response)
            except socket.error as exc:
                print ("Caught exception socket.error : %s" % exc)

                
    def send_command(self, command):
        """
        Send a command to the Tello and wait for a response.
        :param command: Command to send.
        :return (str): Response from Tello.
        """

      #  print (">> send cmd: {}".format(command))
      # 这个地方是把你要发送的字符 以>> send cmd 发送出去 ，这里我们不发送了 ！
        self.abort_flag = False
        timer = threading.Timer(self.command_timeout, self.set_abort_flag)

        self.socket.sendto(command.encode('utf-8'), self.tello_address)

        timer.start()
        while self.response is None:
            if self.abort_flag is True:
                break
        timer.cancel()
        
        if self.response is None:
            response = 'none_response'
        else:
            response = self.response.decode('utf-8')

        self.response = None

        return response
    
    def set_abort_flag(self):
        """
        Sets self.abort_flag to True.
        Used by the timer in Tello.send_command() to indicate to that a response
        
        timeout has occurred.
        """

        self.abort_flag = True

    def takeoff(self):
        """
        Initiates take-off.
        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.
        """

        return self.send_command('takeoff')

    def set_speed(self, speed):
        """
        Sets speed.

        This method expects KPH or MPH. The Tello API expects speeds from
        1 to 100 centimeters/second.

        Metric: .1 to 3.6 KPH
        Imperial: .1 to 2.2 MPH

        Args:
            speed (int|float): Speed.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """

        speed = float(speed)

        if self.imperial is True:
            speed = int(round(speed * 44.704))
        else:
            speed = int(round(speed * 27.7778))

        return self.send_command('speed %s' % speed)

    def rotate_cw(self, degrees):
        """
        Rotates clockwise.

        Args:
            degrees (int): Degrees to rotate, 1 to 360.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """

        return self.send_command('cw %s' % degrees)

    def rotate_ccw(self, degrees):
        """
        Rotates counter-clockwise.

        Args:
            degrees (int): Degrees to rotate, 1 to 360.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """
        return self.send_command('ccw %s' % degrees)

    def flip(self, direction):
        """
        Flips.

        Args:
            direction (str): Direction to flip, 'l', 'r', 'f', 'b'.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """

        return self.send_command('flip %s' % direction)

    def get_response(self):
        """
        Returns response of tello.

        Returns:
            int: response of tello.

        """
        response = self.response
        return response

    def get_height(self):
        """Returns height(dm) of tello.

        Returns:
            int: Height(dm) of tello.

        """
        height = self.send_command('height?')
        height = str(height)
        height = filter(str.isdigit, height)
        try:
            height = int(height)
            self.last_height = height
        except:
            height = self.last_height
            pass
        return height

    def get_battery(self):
        """Returns percent battery life remaining.

        Returns:
            int: Percent battery life remaining.

        """
        
        battery = self.send_command('battery?')

        try:
            battery = int(battery)
        except:
            pass

        return battery

    def get_flight_time(self):
        """Returns the number of seconds elapsed during flight.

        Returns:
            int: Seconds elapsed during flight.

        """

        flight_time = self.send_command('time?')

        try:
            flight_time = int(flight_time)
        except:
            pass

        return flight_time

    def get_speed(self):
        """Returns the current speed.

        Returns:
            int: Current speed in KPH or MPH.

        """

        speed = self.send_command('speed?')

        try:
            speed = float(speed)

            if self.imperial is True:
                speed = round((speed / 44.704), 1)
            else:
                speed = round((speed / 27.7778), 1)
        except:
            pass

        return speed

    def land(self):
        """Initiates landing.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """

        return self.send_command('land')

    def move(self, direction, distance):
        """Moves in a direction for a distance.

        This method expects meters or feet. The Tello API expects distances
        from 20 to 500 centimeters.

        Metric: .02 to 5 meters
        Imperial: .7 to 16.4 feet

        Args:
            direction (str): Direction to move, 'forward', 'back', 'right' or 'left'.
            distance (int|float): Distance to move.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """

        distance = float(distance)

        if self.imperial is True:
            distance = int(round(distance * 30.48))
        else:
            distance = int(round(distance * 100))

        return self.send_command('%s %s' % (direction, distance))

    def move_backward(self, distance):
        """Moves backward for a distance.

        See comments for Tello.move().

        Args:
            distance (int): Distance to move.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """

        return self.move('back', distance)

    def move_down(self, distance):
        """Moves down for a distance.

        See comments for Tello.move().

        Args:
            distance (int): Distance to move.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """

        return self.move('down', distance)

    def move_forward(self, distance):
        """Moves forward for a distance.

        See comments for Tello.move().

        Args:
            distance (int): Distance to move.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """
        return self.move('forward', distance)

    def move_left(self, distance):
        """Moves left for a distance.

        See comments for Tello.move().

        Args:
            distance (int): Distance to move.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """
        return self.move('left', distance)

    def move_right(self, distance):
        """Moves right for a distance.

        See comments for Tello.move().

        Args:
            distance (int): Distance to move.

        """
        return self.move('right', distance)

    def move_up(self, distance):
        """Moves up for a distance.

        See comments for Tello.move().

        Args:
            distance (int): Distance to move.

        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.

        """

        return self.move('up', distance)

# --------------------  Tao   add  -----------------------------------------#
    def get_temp(self):
        
        temp = self.send_command('temp?')

        try:
            temp = str(temp)
        except:
            pass
        
        return temp

    def get_attitude(self):
        
        attitude = self.send_command('attitude?')

        return attitude

    def get_baro(self):
        
        baro = self.send_command('baro?')
        try:
            baro = str(baro)
        except:
            pass

        return baro


    def get_acceleration(self):
        
        acceleration = self.send_command('acceleration?')

        return acceleration

    def get_tof(self):
        
        tof = self.send_command('tof?')

        try:
            tof = str(tof)
        except:
            pass

        return tof

    def get_wifi(self):
        
        wifi = self.send_command('wifi?')

        return wifi


# --------------------  Tao   add  end  -----------------------------------------#
    def land(self):
        """Initiates landing.
        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.
        """

        return self.send_command('land')

    def move(self, direction, distance):
        """Moves in a direction for a distance.
        This method expects meters or feet. The Tello API expects distances
        from 20 to 500 centimeters.
        Metric: .02 to 5 meters
        Imperial: .7 to 16.4 feet
        Args:
            direction (str): Direction to move, 'forward', 'back', 'right' or 'left'.
            distance (str|float): Distance to move.
        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.
        """

        distance = float(distance)

        if self.imperial is True:
            distance = str(round(distance * 30.48))
        else:
            distance = str(round(distance * 100))

        return self.send_command('%s %s' % (direction, distance))

    def move_backward(self, distance):
        """Moves backward for a distance.
        See comments for Tello.move().
        Args:
            distance (str): Distance to move.
        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.
        """

        return self.move('back', distance)

    def move_down(self, distance):
        """Moves down for a distance.
        See comments for Tello.move().
        Args:
            distance (str): Distance to move.
        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.
        """

        return self.move('down', distance)

    def move_forward(self, distance):
        """Moves forward for a distance.
        See comments for Tello.move().
        Args:
            distance (str): Distance to move.
        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.
        """
        return self.move('forward', distance)

    def move_left(self, distance):
        """Moves left for a distance.
        See comments for Tello.move().
        Args:
            distance (str): Distance to move.
        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.
        """
        return self.move('left', distance)

    def move_right(self, distance):
        """Moves right for a distance.
        See comments for Tello.move().
        Args:
            distance (str): Distance to move.
        """
        return self.move('right', distance)

    def move_up(self, distance):
        """Moves up for a distance.
        See comments for Tello.move().
        Args:
            distance (str): Distance to move.
        Returns:
            str: Response from Tello, 'OK' or 'FALSE'.
        """

        return self.move('up', distance)

    def set_go_xyz_speed(self, x, y, z, speed):
        """Fly to x y z relative to the current position.
        Speed defines the traveling speed in cm/s.
        Arguments:
            x: -500-500
            y: -500-500
            z: -500-500
            speed: 10-100
        """
        cmd = 'go {} {} {} {}'.format(x, y, z, speed)
        go_xyz_speed = self.send_command(cmd)

        return go_xyz_speed

    def set_send_rc_control(self, left_right_velocity, forward_backward_velocity, up_down_velocity,
                        yaw_velocity):
        """Send RC control via four channels. Command is sent every self.TIME_BTW_RC_CONTROL_COMMANDS seconds.
        Arguments:
            left_right_velocity: -100~100 (left/right)
            forward_backward_velocity: -100~100 (forward/backward)
            up_down_velocity: -100~100 (up/down)
            yaw_velocity: -100~100 (yaw)
        """
        cmd = 'rc {} {} {} {}'.format(left_right_velocity, forward_backward_velocity, up_down_velocity, yaw_velocity)
        send_rc_control = self.send_command(cmd)
