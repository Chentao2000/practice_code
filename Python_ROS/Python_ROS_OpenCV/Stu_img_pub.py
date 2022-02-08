#!/usr/bin/env python
# coding:utf-8
from email import header
from importlib import resources
from tracemalloc import start
from turtle import stamp
import cv2
import numpy as np
import rospy
from std_msgs.msg import Header
from sensor_msgs.msg import Image
from cv_bridge import CvBridge ,CvBridgeError
import time

if  __name__ == "__main__":
    captrue  = cv2.VideoCapture(0) # 定义摄像头
    # 我记得这个地方 取 0 就是取电脑默认摄像头 ，1~ 就是其他摄像头
    rospy.init_node('camera_node',anonymous= True)# 定义这个节点
    image_pub = rospy.Publisher('/image_vie/image_raw',Image,queue_size=1)# 定义这个话题

    while not rospy.is_shutdown(): # Ctrl c 正常退出 如果异常退出会报错 device busy !
        start = time.time()
        ret , frame = captrue.read()
        if ret : #如果有画面再执行
            
            frame = cv2.flip(frame , 1) # 水平镜像操作
            
            ros_frame = Image()

            header = Header(stamp = rospy.Time.now())
            header.frame_id = "Camera"
            ros_frame.header = header
            ros_frame.width = 640
            ros_frame.height = 480
            ros_frame.encoding = "brg8"
            ros_frame.step = 1920
            ros_frame.data = np.array(frame).tostring() # 图片转换格式
            image_pub.publish(ros_frame) # 发布消息
            end = time.time() 
            print ( "  const time " ,end-start) # 看一下每一帧的执行实践 ，从而确定合适的rate
            rate = rospy.Rate(25) #10hz
        
        captrue.release()
        cv2.destroyAllWindows()
        print("quit successfully!")
            
            
    