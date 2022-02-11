
# -*- coding: utf-8 -*- 
from __future__ import print_function
from cv2 import imshow
import numpy as np
import argparse
import mahotas
import cv2


# Construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
	help = "Path to the image")
args = vars(ap.parse_args())


# 加载图像  转换灰度  稍微模糊
image = cv2.imread( args["image"])
image = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(image,(5,5),0)
cv2.imshow("image",image)
# Opencv 提供值的方法使用 Otus 阈值（thresholding） 但是我们发现
# 这个 mahotas ？（python库） 实施（implementation）是更加 Pythonic
# Otsu's 方法（method）假定 （assumes）灰度的直方图有两个 “峰值”
# 它寻找这些 峰值 并且转换成一个值 我们应当设置 阈值 （threshold）在上面

T = mahotas.thresholding.otsu(blurred)
print("Otsu 's threshold : {}".format(T))


# 可以使用 NumePy 设置阈值
# 小于 阈值的值可以设置 成 0 ，大于阈值的值可以设置成255 

thresh = image.copy()
thresh[thresh>T] = 255
thresh[thresh <255] = 0
thresh = cv2.bitwise_not(thresh)
cv2.imshow("Ostu",thresh)

# 另一种可替代的是使用 Riddler-Calvard 方法
T = mahotas.thresholding.rc(blurred)
print("Riddler-Calvard.{}".format(T))
thresh = image.copy()
thresh[thresh > T  ] = 255
thresh[thresh < 255] =0
thresh = cv2.bitwise_not(thresh)
cv2.imshow("Riddler- Calvard",thresh)
cv2.waitKey(0)







