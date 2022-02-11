
# -*- coding: utf-8 -*- 
from cv2 import blur
import numpy as np
import argparse 
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i" , "--image",required= True,help = "Path to the image")
args = vars(ap.parse_args())


image = cv2.imread(args["image"])
image = cv2.cvtColor(image , cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(image,(5,5),0)
cv2.imshow("image" , image )


# 让我们应用基本阈值（thresholding）这第一个 parmeter （参数）
image = cv2.imread(args["image"])
image = cv2.cvtColor(image , cv2.COLOR_BGR2GRAY)
blur = cv2.GaussianBlur(image , (5 ,5 ), 0)
cv2.imshow("image ",image)


# 我们应用基本阈值 ，这首先的元素是 这图像 我们想要的阈值 
# 这第二个值 是我们阈值  的cehck？ 
# 如果一个像素值作为阈值是 跟大我们的阈值 ，我们让它变成白色
# 否则变成白色

(T , threshlnv) = cv2.threshold(blurred , 155,255, cv2.THRESH_BINARY_INV)
cv2.imshow(" Threshold Binary Inverse ", threshlnv)


# 使用一个保证 我们能改变最后一个像素值在功能
# 去使我们的硬币变成变色而非白色 
(T ,thresh ) = cv2.threshold(blurred , 155 ,255 ,cv2.THRESH_BINARY)
cv2.imshow("Threshold Binary",thresh)

# 最终 让我们开始使用mask 作为可视化（visualize）出来 
# 这个硬币在这个图像中 

cv2.imshow("Coins", cv2.bitwise_and(image , image ,mask = threshlnv))
cv2.waitKey(0)
