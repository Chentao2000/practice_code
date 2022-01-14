#!/usr/bin/env python
# -*- coding: utf-8 -*-
# 干就完事了！！！！
# 在上面基础上面 去掉了 cv
from distutils import command
import os
import queue
from re import S
import string
import sys
import threading
import time
import rospy
from std_msgs.msg import  String
from sensor_msgs.msg import image
import tello_base as tello
# 我们是不用 cv 的，把一切cv去掉

def callback(data,drone):
    command  = data.data
    drone.send_command(command)


def subscribe():
    rospy.Subscriber("command",string,callback, drone )
    # rospy.spin()

def control():
    pass
# 如果你发送command 给tello 不用 ros，例如  ，如果你使用这个功能
	# drone.send_command("takeoff")
	# drone.send_command("go 0 50 0 10")
	# drone.send_command("land")
	# print drone.send_command("battery?")
        # drone.send_command("mon")
        # print("mon")


if __name__ == '__main__':
    drone = tello.Tello('',8888)
    rospy.init_node('tello_state',String,queue_size =3 )
    state_pub  = rospy.Publisher("tello state",string,queue_size=3)
    img_pub = rospy.Publisher("tello_image",image,queue_size= 5)

    # 你可以订阅此命令行，或者你可以仅仅使用 command这个功能
    sub_thread = threading.Thread(target=subscribe)
    sub_thread.start()
    # 你可以不使用 ROS ，或者你可以仅仅使用commit 这个功能
    con_thread = threading.Thread(target=control)
    con_thread.start()
    try:
		while not rospy.is_shutdown():

			state=drone.read_state()
			if state is None or len(state) == 0:
				continue
			tello_state="".join(state)
			state_pub.publish(tello_state)

			frame = drone.read_frame()
			if frame is None or frame.size == 0:
				continue
	except rospy.ROSInterruptException:
		pass
