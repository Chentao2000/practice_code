# -*- coding: utf-8 -*-
from __future__ import  print_function
import numpy  as np
import argparse
import cv2 


# Construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
	help = "Path to the image")
args = vars(ap.parse_args())


# Load the image, convert it to grayscale, and blur it slightly
image = cv2.imread(args["image"])

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

blurred = cv2.GaussianBlur(gray, (11, 11), 0)

cv2.imshow("Image", image)


# 这第一件事是应用 边缘检测 的结果 
# 这个图像是 揭示了线外这 些硬币

edged = cv2.Canny(blurred , 30 ,150)
cv2.imshow("Edgaes",edged)


# 寻找 这个 轮廓线条 (controus) 在边缘检测图像中 
# 笔记 ： 这 cv2.findContours 方是 破坏性的 （DESTRUCTIVE）对这个图像 
#放进去 后 ，如果你进入再利用 你的边缘检测图像 
# 确保你复制一遍后再 回调 它 CV2这个图像 

( __ ,cnts,__) = cv2.findContours(edged.copy(), cv2.RETR_EXTERNAL , cv2.CHAIN_APPROX_SIMPLE)

# 多少 轮廓线 contours  我们寻找到 的
print(" i count {} coins in thisimage ".format(len(cnts)))


#让我们高亮这写硬币在起源的图像在画上一个绿色的圆圈在周围 
coins = image.copy()
cv2.drawContours(coins,cnts, -1,(0,255,0) ,2)
cv2.imshow("Coins",coins)
cv2.waitKey(0)

# 现在 让我们闭环检测 每个边缘 
for (i,c ) in enumerate (cnts):
    #我们可以计算这 “包裹 （bounding）盒子  在这个轮廓中 
    # 每个 这个 长方形 包围 encloses 这个轮廓线条
    ( x ,y ,w ,h) = cv2.boundingRect(c)

    # 现在 我们用浙西轮廓线 ，让我们开转使用灰度图
    # slices ： 片
    print("Coin #{}".format(i+1))
    coin = image[y:y + h , x:x +w]
    cv2.imshow("Coin" , coin)
    # 仅仅为了好玩 ，让我们通过以下方法构成一个硬币
    # 这 最小包围圆圈在这个轮廓线中 
    #
    mask = np.zeros(image.shape[:2], dtype = "uint8")
    ((centerX, centerY), radius) = cv2.minEnclosingCircle(c)
    cv2.circle(mask, (int(centerX), int(centerY)), int(radius), 255, -1)
    mask = mask[y:y + h, x:x + w]
    cv2.imshow("Masked Coin", cv2.bitwise_and(coin, coin, mask = mask))
    cv2.waitKey(0)
