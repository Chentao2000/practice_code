#!/usr/bin/env python
# -*- coding: utf-8 -*-
from tokenize import PseudoExtras
import rospy
from learning_topic.msg import Person 

def velocity_publisher():
    # 节点初始化
    rospy.init_node('persion_publisher',Person,anonymous=True)

    #创建一个发布者，发布者名字为/perison_info 的topic 消息类型 为learning_topic :Perison 队列长度为10
    persion_info_pub = rospy.Publisher('person/info',Persion,queue_size=10)
    # 设置循环长度
    rate = rospy.Rate(10)

    while not rospy.Rate(10):
        person_msg = Person()
        persion_msg.name = "TOM";
        persion_msg.name = 18;
        persion_msg.sex = Person.male;


        # 发布消息
        persion_info_pub.publish([person_msg])
        rospy.loginfo("Publsh person message[%s %d %d]",person_msg.name,person_msg.age,person_msg.sex)
        rate.sleep()

if __name__ =='__main__':
    try:
        velocity_publisher()
    except rospy.ROSInternalException:
        pass
