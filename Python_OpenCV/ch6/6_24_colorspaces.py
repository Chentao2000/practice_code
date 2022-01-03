# -*- coding: utf-8 -*- 
import numpy as np
import argparse
import cv2


# 构件解析器参数

ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help= "path to the image")
args = vars(ap.parse_args())




#加载图像并且显示它
image = cv2.imread(args["image"])
cv2.imshow("Original", image)



# 转换成灰度
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
cv2.imshow("Gray", gray)


# 转换成 HSV  Hue 色调  Satuaration 饱和度 Value  值
# 颜色空间
hsv = cv2.cvtColor(image,cv2.COLOR_BGR2LAB)
cv2.imshow("HSV",hsv)


# 转换成 LAB 图色彩空间
lab = cv2.cvtColor(image,cv2.COLOR_BGR2LAB)
cv2.imshow("L A B",lab)
cv2.waitKey(0)

