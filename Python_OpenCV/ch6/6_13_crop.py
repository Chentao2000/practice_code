
# -*- coding: utf-8 -*- 
import numpy as np  
import argparse
import cv2


# 构造解析器解析参数
ap =argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="Path to the image")
args = vars(ap.parse_args())

#加载图像并且显示它
image = cv2.imread(args["image"])
cv2.imshow("Original",image)


# 裁剪图像就使用阵列切片一样简单
# 在NumPy 让我们切割恐龙的脸 
# 在 Y  30 -120  X 240 - 355 位置
# 根据实际 我修改了一下大小 cropped = image[30:600,40:300]

cropped = image[30:600,40:300]
cv2.imshow("T-Rex Face",cropped)
cv2.waitKey(0)
