# -*- coding: utf-8 -*- 
import numpy as np
import argparse
import cv2


# Construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
	help = "Path to the image")
args = vars(ap.parse_args())


# 加载这个图像 ，转换成灰度图  然后稍微模糊以下 
#  稍微去除一下我们没有的高频 ( Frequency 高频率的)边缘
#   感兴趣 集中 

image = cv2.imread(args["image"])
image = cv2.cvtColor(image , cv2.COLOR_BGR2GRAY)
image = cv2.GaussianBlur(image,(5,5,) , 0)
cv2.imshow("Blurred",image)

# 当 执行（performing）  边缘检测 （edge detection） 我们需要两个值对于我们相对 滞后的（ hysteresis : 滞后的）值 
# 任何 梯度大于 阈值2 都会被视作边缘
# 低于阈值1 的将不被视其为边缘
# 值 将在 阈值 1 和 阈值2  之间 
# 并且根据分类方式 分为边 和非边
# 这 有趣的 案例
# 在这个案列中 ，任何 坡度 （gradient）值在 30以下 是被证明 没有边缘  
# 在 150以上被视为 有边缘
canny  = cv2.Canny(image ,30 ,150)
cv2.imshow("Canny",canny)
cv2.waitKey(0)
