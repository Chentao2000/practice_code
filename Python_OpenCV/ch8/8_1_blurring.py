import numpy as np
import argparse
import cv2
from numpy.lib.type_check import imag



ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
	help = "Path to the image")
args = vars(ap.parse_args)


# 加载图像并且显示它

image = cv2.imread(args["image"])
cv2.imshow("Orignial",image)

# 让我们先定义平均的标准，取所有像素的范围只取平均值，并用平均值取代中心图像
# 因此 目的在于中心区域
# 这个空间内必须的奇数（odd），下面举了一些例子 有者不同的内核，
# 注意 内核越大 会变得越模糊
blurred = np.hstack([
	cv2.GaussianBlur(image, (3, 3), 0),
	cv2.GaussianBlur(image, (5, 5), 0),
	cv2.GaussianBlur(image, (7, 7), 0)])
cv2.imshow("Gaussian", blurred)
cv2.waitKey(0)

# The cv2.medianBlur  主要的消除椒盐噪声（平均）
blurred = np.hstack([
	cv2.medianBlur(image, 3),
	cv2.medianBlur(image, 5),
	cv2.medianBlur(image, 7)])
cv2.imshow("Median", blurred)
cv2.waitKey(0)

#模糊有助于消除消除噪声，但也会使得边缘不太锐利，我们可以使用双边滤波
blurred = np.hstack([
	cv2.bilateralFilter(image, 5, 21, 21),
	cv2.bilateralFilter(image, 7, 31, 31),
	cv2.bilateralFilter(image, 9, 41, 41)])
cv2.imshow("Bilateral", blurred)
cv2.waitKey(0)
