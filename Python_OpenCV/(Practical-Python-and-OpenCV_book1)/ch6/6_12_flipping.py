# -*- coding: utf-8 -*-
import argparse
import cv2


# 构造解析器并解析参数
ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="path to the image")
args = vars(ap.parse_args())


# 放入一个图像并展示它
image = cv2.imread(args["image"])
cv2.imshow("Oraiginal",image)

# 水平翻转图像
flipped = cv2.flip(image,1)
cv2.imshow("Flipped Horizontally",flipped)

# 垂直翻转图像
flipped = cv2.flip(image,0)
cv2.imshow("Flipped Vertically",flipped)


# Filp the image along both axes
flipped = cv2.flip(image,-1)
cv2.imshow("Flipped Horizontally & Vertically",flipped)
cv2.waitKey(0)
