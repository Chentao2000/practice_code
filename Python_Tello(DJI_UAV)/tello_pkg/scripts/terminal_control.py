#!/usr/bin/env python
# -*- coding: utf-8 -*-

import  rospy
import my_tello
import threading
from std_msgs.msg import String
from time import sleep

takeoff_flag = 0  # 起飞降落的标志位
move_x =  0 #  move_x 移动 x 
move_y =  0 # move_y  移动 y 
move_z =  0 # move_z 移动 z 
left_right_velocity = 0 
forward_backward_velocity = 0
up_down_velocity =0 
yaw_velocity =0 



def  publisher():
    global pub
    global move_x
    global move_y
    global move_z
    global left_right_velocity 
    global forward_backward_velocity
    global up_down_velocity
    global yaw_velocity 

    pub = rospy.Publisher("command",String,queue_size=10 )
    # 全局共享 两种运动模式的 变量

def param():
    while not rospy.is_shutdown():
        input_msg = input("Please input the control command to the UAV   1 : takeoff   2 : land  3 : move_xyz  4 : attitude_abcd ")
        if  input_msg == 1 :
            pub_msg = "takeoff"
            pub.publish(pub_msg)
            print("tello takeoff ! \r\n")
        elif input_msg == 2:
            pub_msg = "land"
            pub.publish(pub_msg)
            print("tello land ! \r\n")
        elif input_msg == 3:
            move_x = input(" move x  cm:")
            move_y = input("move y  cm :")
            move_z = input("move z  cm :")
            pub_msg = 'go {} {} {} {}'.format(move_x, move_y, move_z, 100)
            pub.publish(pub_msg)
            print( " move x :   "   + str(move_x)   + " move y :  " +    str(move_y ) + "  move z :   "+ str (move_z))
        elif input_msg == 4:
            left_right_velocity =  input(" left_right_velocity （-100 ~ 100）:   ")
            forward_backward_velocity =input(" forward_backward_velocity （-100 ~ 100）:     ")
            up_down_velocity =input(" up_down_velocity （-100 ~ 100）:  ")
            yaw_velocity =  0   # input(" yaw_velocity （-100 ~ 100）:  ")   旋转 ：   默认是0 不旋转
            pub_msgcmd = 'rc {} {} {} {}'.format(left_right_velocity, forward_backward_velocity, up_down_velocity, yaw_velocity)
            pub.publish(pub_msgcmd)
            print( " left_right  :   "   + str(left_right_velocity)   + "forward_backward  :   " +    str(forward_backward_velocity ) + "up_down :   "+ str (up_down_velocity)+  "up_down :   " + str(yaw_velocity) + " \r\n")
        else :
            print(" Please enter the correct number   1 : takeoff      2 : land  3 : move_xyz    4 :attitude_abcd  ")


        
def  thread_start():  
    # 多线程 循环 更新状态 命令 输入
    tellostate_update_thread = threading.Thread(target=start_update)
    tellostate_update_thread.start()
    cmd_control_thread = threading.Thread(target=param)
    cmd_control_thread.start()

if __name__=='__main__':
    rospy.init_node('terminal_control', anonymous=True)
    thread_start()

     