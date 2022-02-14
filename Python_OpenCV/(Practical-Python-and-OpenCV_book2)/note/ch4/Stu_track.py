# USAGE
# python Stu_track.py --video video/iphonecase.mov

# import the necessary packages

import numpy as np
import argparse
import time
import cv2


ap = argparse.ArgumentParser()
ap.add_argument("-v", "--video",
	help = "path to the (optional) video file")
args = vars(ap.parse_args())

# 定义颜色的上下边界 
#设定一个阈值 为 “ 蓝色  ”

blueLower = np.array([100, 67, 0], dtype = "uint8")
blueUpper = np.array([255, 128, 50], dtype = "uint8")

# 加载摄像头 

camera = cv2.VideoCapture(args["video"])

while True:
    # 抓取当前帧
    (grabbed , frame) = camera.read()
    # 检查 我们是否到了结尾
    if  not grabbed:
        break

    # 确定那些图像落在了蓝色边界内
    # 然后对图像进行二值化处理 
    blue = cv2.inRange(frame , blueLower , blueUpper)
    blue = cv2.GaussianBlur(blue , ( 3 ,3) , 0)

# 在图像中寻找轮廓
    (_, cnts, _) = cv2.findContours(blue.copy(), cv2.RETR_EXTERNAL,
		cv2.CHAIN_APPROX_SIMPLE)
    # 查看是否有任何的轮廓
    if len(cnts) > 0 :
# 对轮廓进行排序并找到最大的轮廓——我们将假设这个轮廓对应于我手机的区域#
        cnt = sorted(cnts,key=cv2.contourArea , reverse= True)[0]

# 计算周围的（旋转的）边界框
# 轮廓然后绘制它
        rect = np.int32(cv2.boxPoints(cv2.minAreaRect(cnt)))
        cv2.drawContours(frame , [rect] , -1 , ( 0,255,0) , 2) 

    cv2.imshow(" Tracking", frame)
    cv2.imshow(" Binary",blue)

# 如果你的机器速度很快，它可能会显示帧
# 自 32  帧以上以来似乎是“快进”的内容
# 每秒帧数正在显示——一个简单的 hack
# 只是在帧之间睡一点点；
# 然而，如果你的电脑很慢，你可能想要
# 注释掉这一行
    time.sleep(0.025)

    if cv2.waitKey(1) & 0xFF  == ord("q"):
        break

camera.release()
cv2.destroyAllWindows()

