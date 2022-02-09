# -*- coding: utf-8 -*- 
from __future__ import print_function
import numpy as np
import argparse
import cv2

# 构造参数解析器解析参数
ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="Path to the image")
args = vars(ap.parse_args())


# 加载图像并且显示它
image = cv2.imread(args["image"])
cv2.imshow("Original", image)

# 图像是 一个数组 ，无符号8位数整形
# 这意味着我们像素区间在 【0  255】
# 当我们使用 cv2.add  (加 )  cv.2subtract （减） 这样的函数
# 把数组裁剪到 此范围 ，甚至可以超出这个范围
print("max of 255: {}".format(cv2.add(np.uint8([200]), np.uint8([100]))))
print("min of 0: {}".format(cv2.subtract(np.uint8([50]), np.uint8([100]))))

# 如果你的数组 Numpy 运算 这些值将是模块 在 0 ，255范围 ，而不是超出 
#这是非常重要因为在这个工作区间
print("wrap around: {}".format(np.uint8([200]) + np.uint8([100])))
print("wrap around: {}".format(np.uint8([50]) - np.uint8([100])))

#让我们增加图像中所有像素的强度
#到100。我们通过构造一个NumPy数组来实现这一点
#这与我们的矩阵大小相同（充满了）
#然后将其乘以100，创建一个填充的数组
#用100。然后我们简单地把图像加在一起。注意
#怎么样这个图像将变亮
M = np.ones(image.shape, dtype = "uint8") * 200
## 这句话的意思是 创建一个图像一样的参数 ；然后每个都是 1 ，让它乘以100 ，然后加起来
## 还好我记得 np.one 是怎么来的哈哈哈哈！！
added = cv2.add(image, M)
cv2.imshow("Added", added)
added

# 同样的 ，我们用相同的方法处设立
#  图像将变得更暗
M = np.ones(image.shape, dtype = "uint8") * 200
subtracted = cv2.subtract(image, M)
cv2.imshow("Subtracted", subtracted)
cv2.waitKey(0)
