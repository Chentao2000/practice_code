#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from turtlesim.msg import Pose

def poseCallback(msg):
    rospy.loginfo("Turtle pose : x : %0.6f , %0.6f", msg.x ,msg.y)

def pose_subscriber():
    # ROS 节点初始化
    rospy.init_node('pose_subscriber',anonymous=True)
    
    # 创建一个 subscriber 订阅名为 tutrle1/pose 的topic 注册回调函数poseCallback
    rospy.Subscriber('/turtle1/pose',Pose,poseCallback)

    # 循环等待回调函数
    rospy.spin()

if __name__ == '__main__':
    pose_subscriber()
