# 为了 学习 tello.base 官方库而创建 ...
# 那个 做 项目之前一定要学会适应环境 ... 给自己一点时间...
import socket
import threading
import time
import numpy as np
import libh264decoder
from stats import Stats
# 可以断定上面是官方文件夹 ，放心使用

class Tello:
    # 下面就是tello 全部包装 
    def __init__(self,local_ip,local_port,imperial=False,command_timeout=.3,tello_ip ='192.168.10.1',
                            tello_port = 8889):
        # 绑定的时候 4个参数不能完全一致， 可以通过路由器才看它的端口什么的..
        """
        Binds to the local IP/port and puts the Tello into command mode.

        :param local_ip (str): Local IP address to bind.
        :param local_port (int): Local port to bind.
        :param imperial (bool): If True, speed is MPH and distance is feet.
                             If False, speed is KPH and distance is meters.
        :param command_timeout (int|float): Number of seconds to wait for a response to a command.
        :param tello_ip (str): Tello IP.
        :param tello_port (int): Tello port.
        """
        # 看上面的参数用的
        self.last = False
        self.command = "  "# for debug
        self.abort_flag = False
        self.imperial = imperial  # 不太清楚这个是干什么的

        self.response = None  
        self.frame = None  # numpy阵列BGR——当前相机输出帧
        self.is_freeze = False  # 冻结相机当前输出
        self.last_frame = None # 最后一幅图像

        self.log = []
        self.MAX_TIME_OUT = 10.0

        self.socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # socket for sending cmd
        # 这个是为了发送CMD 输出 
        self.socket_video = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  # socket for receiving video stream
        #此模块提供套接字操作和一些相关功能。在Unix上，它支持IP（Internet协议）和Unix域套接字
        self.tello_ip=tello_ip  #  输入参数
        self.tello_address = (tello_ip, tello_port) # 地址两个参数（输入 ip 和 输出端口）
        self.local_video_port = 11111  #接收的视频扣
        self.last_height = 0       
        self.socket.bind((local_ip, local_port))  # 绑定 ip  和端口
        # 创建一个接收的线程 cmd ack
        self.receive_thread = threading.Thread(target=self._receive_thread)
        self.receive_thread.daemon = True   #  啊啊啊啊 daemon 是意思 ： 状态？
        self.receive_thread.start() # 开始

        # 要接收视频，请发送cmd:command，streamon
        self.socket.sendto(b'command', self.tello_address)
        print ('sent: command')
        self.socket.sendto(b'streamon', self.tello_address)
        print ('sent: streamon')
        #-----------------  这个就是一个很开始
        self.socket_video.bind((local_ip, self.local_video_port))
        # 这个是绑定 的 ip 和视频端口  ....


        # 状态接收：
        self.results=None
        self.socket_state.bind((local_ip,8890))
        self.receive_state_thread=threading.Thread(target=self._recevie_state_thread)
        self.receive_state_thread.daemon=True
        self.receive_state_thread.start()

        # ------------------------  接下来就是对上面指令进行解释了 ...

    def read_frame(self):
        """Return the last frame from camera."""
        if self.is_freeze:
            return self.last_frame
        else:
            return self.frame

    def read_state(self):
        if self.results=='ok' or self.results==None:
            return self.results
        else:
            return self.results[0:8]

    def video_freeze(self, is_freeze=True):
        """Pause video output -- set is_freeze to True"""
        self.is_freeze = is_freeze
        if is_freeze:
            self.last_frame = self.frame
 
 #  电视台的回应。作为线程运行，设置自身。对Tello最后返回的内容的响应

    def _receive_thread(self):
        while True:
            try:
                state, ip = self.socket_state.recvfrom(1024)
                out = state.replace(';', ';\n')
                self.results = out.split()
                print("received result: " + str(self.results) )
                # 如果 报错就返回它...
            except socket.error as exc:
                print ("Caught exception socket.error : %s" % exc)

#          decode raw h264 format data from Tello :param packet_data: raw h264 data array   :return: a list of decoded frame
# 这个 就是关于 h264 的文件了 ，如果我们不用 视频 是不是就可以去掉它算了！
    def _h264_decode(self, packet_data):
# 把一个图像转换成 一个数组... (大概意思就是这样把)
        res_frame_list = []
        frames = self.decoder.decode(packet_data)
        for framedata in frames:
            (frame, w, h, ls) = framedata
            if frame is not None:
                # print 'frame size %i bytes, w %i, h %i, linesize %i' % (len(frame), w, h, ls)

                frame = np.fromstring(frame, dtype=np.ubyte, count=len(frame), sep='')
                frame = (frame.reshape((h, ls / 3, 3)))
                frame = frame[:, :w, :]
                res_frame_list.append(frame)

        return res_frame_list


        # 好了 ，这个就是发送命令 ，发送一个命令给Tello等待回应：
def send_command(self, command):
    # 五花八门的  ，让我来一行一行分析看看...
        self.log.append(Stats(command, len(self.log)))
        # append 这个 是 ：判断字节长度 ？
        print(">> send cmd: {}".format(command))
        # 这个是答应 你发送的 send cmd ， 打印你发送的...
        print(len(self.log),self.log[-1].got_response())
        # 返回  长度 .. 得到的响应？
        self.socket.sendto(command.encode('utf-8'), self.tello_address)
        # 告诉 套 字件， 发送出去 的编码的 utf -8， 发送的是地址
        #  这个函数难道就是传说的发送字节吗： 
        #               self.socket.sendto  （ 内容 ） （地址）
        #
        print(len(self.log),self.log[-1].got_response())
        # 答应 ，又是 答应回答的东西
        self.last = self.log[-1].got_response()
        # 最后一次回答保存下来 （瞎猜）
        start = time.time()
        #print(self.log[-1].got_response())
        timelen = 0.
        # 时间长度
        while True:
                 # 真实循环
            if not self.log[-1].got_response():
                # 如果没有得到回应
                continue
            elif (not self.last) and('ok' in str(self.log[-1].got_response())):
                break
            # 如果超过了最短实践 ，或者获取了返回 ok 那退出了
            elif ('ok' in str(self.last)) and('ok' in str(self.log[-1].got_response())):
                # 不懂 ↑？？？？？↓ ？？？
                self.last = self.log[-1].got_response()
                continue
            elif 'ok' not in str(self.log[-1].got_response()):
                now = time.time()
                diff = now - start
                if diff > timelen:
                    print(self.log[-1].got_response())
                    timelen += 1.
                    self.socket.sendto(command.encode('utf-8'), self.tello_address)
                #print(len(self.log))
                if diff > self.MAX_TIME_OUT:
                    # 如果超过了最大时间，则直接发送这个 超时
                    print ('Max timeout exceeded... command %s' % command)  
                    raise Exception('command timeout')
        # 最后发送成功了 ，打印发送成功的字！    
        print ('Done!!! sent command: %s to %s' % (command, self.tello_ip))
        print (self.log[-1].got_response())
        return self.log[-1].got_response()
