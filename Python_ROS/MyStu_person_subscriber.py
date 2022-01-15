#!/usr/bin/env python
# -*- coding: utf-8 -*-
import imp
import rospy
from learning_topic.msg import Persion

def personInfoCallback(msg):
    rospy.loginfo("Subcribe Person info :name :%s age %d sex %d",msg.name,msg.age,msg.sex)

def person_subscriber():
    # ROS节点初始化
    rospy.init_node('person_subscriber',anonymous=True)

    # 创建一个提交者，订阅person_info 的topic 注册毁掉函数 personinfocallback
    rospy.SubscribeListener('/person_info',Persion,personInfoCallback)

    # 循环等待回调函数
    rospy.spin()

    if __name__ == '__main__':
        person_subscriber()
        

