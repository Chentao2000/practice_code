#!/usr/bin/env python
# -*- coding: utf-8 -*-

import turtle
import rospy
from geometry_msgs.msg import Twist

def velocity_publisher():
    # ROS 节点初始化
    rospy.init_node('velocity_publisher',anonymous=True)
    # 创建一个Publisher 发布名为 /turtle1/cmd_vel的 topic 消息类型为 geometry_msgs :Twist ，队列长度为 10
    turtle_vel_pub = rospy.Publisher('/tutle1/cmd_vel',Twist,queue_size=10)
    # 设置循环频率
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        # 初始化 geome_msgs ::Twist 类型的消息
        vel_msg = Twist()
        vel_msg.linear.x=0.5
        vel_msg.linear.y = 0.2

        # 发布消息
        turtle_vel_pub.publish(vel_msg)
        rospy.loginfo(" 发布海龟的话题 [ %0.2f m/s ,%0.2f rad/s ] ",vel_msg.linear.x,vel_msg.linear.y)
        rate.sleep()

if __name__==  '__main__' :
    try:
        velocity_publisher()
    except rospy.ROSInternalException:
        pass


