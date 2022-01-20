#!/usr/bin/env python
# -*- coding: utf-8 -*-
import threading
from time import sleep
import my_tello
import rospy
from std_msgs.msg import String
from tello_pkg.msg import Mytellostate
import numpy as np
import tf
      

pos_offset = np.array(((0,0,0)))  # 初始偏差
_odom_valid  = True # 标志位 
object_name = "tello_obj"
global drone
def callback(data ,drone):
    command = data.data
    drone.send_command(command)

def subscribe():
    rospy.Subscriber("command",String,callback,drone)

def start_update():
    while not rospy.is_shutdown():
        drone.send_command("wifi?")
        sleep(1)

# python tuple  = C++ const 但是在python 中好像根本没必要
def mocap_cb(msg ):
    global _odom_valid
# 位置 -- optitrack系 到 ENU系
#Frame convention 0: Z-up -- 1: Y-up (See the configuration in the motive software)
    optitrack_frame =0
    if optitrack_frame == 0:
        # / Read the Drone Position from the Vrpn Package [Frame: Vicon]  (Vicon to ENU frame)
        pos_drone_mocap = np.array(((msg.pose.position.x,msg.pose.position.y,msg.pose.position.z)))
        pos_drone_mocap[0] = pos_drone_mocap[0] - pos_offset[0]
        pos_drone_mocap[1] = pos_drone_mocap[1] - pos_offset[1]
        pos_drone_mocap[2] = pos_drone_mocap[2] - pos_offset[2]
        q_mocap = np.array(((msg.pose.orientation.w, msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z)))
    else:
        pos_drone_mocap = np.array(((-msg.pose.position.x, msg.pose.position.z, msg.pose.position.y)))
        # Read the Quaternion from the Vrpn Package [Frame: Vicon[ENU]]
    #  C++ :  q_mocap = Eigen::Quaterniond(msg.pose.orientation.w, msg.pose.orientation.x, msg.pose.orientation.z, msg.pose.orientation.y); 
        # //Y-up convention, switch the q2 & q3
        pos_drone_mocap[0] = pos_drone_mocap[0] - pos_offset[0]
        pos_drone_mocap[1] = pos_drone_mocap[1] - pos_offset[1]
        pos_drone_mocap[2] = pos_drone_mocap[2] - pos_offset[2]
        #     // Transform the Quaternion to Euler Angles
        #  
        Euler_mocap  =tf.transformations.quaternion_from_euler(pos_drone_mocap)  # 旋转
        _odom_valid= True
    
        last_timestamp = msg.header.stamp

    pass

#     // 【订阅】optitrack估计位置
#    ros::Subscriber optitrack_sub = nh.subscribe<geometry_msgs::PoseStamped>("/vrpn_client_node/"+ object_name + "/pose", 100, mocap_cb);

def   sub_vrpn():
    vrpn_sub = rospy.Subscriber("/vrpn_client_node/"+ object_name + "/pose",100,mocap_cb)
    pass

def pid():
    pass


def sub_and_pub():
    subscribe()
   
def  thread_start():  
    # 多线程 循环 更新状态 命令 输入
    tellostate_update_thread = threading.Thread(target=start_update)
    tellostate_update_thread.start()




if __name__=='__main__':
    drone = my_tello.Tello('',8888)
    rospy.init_node('tello_control', anonymous=True)
    sub_and_pub()
    
     
