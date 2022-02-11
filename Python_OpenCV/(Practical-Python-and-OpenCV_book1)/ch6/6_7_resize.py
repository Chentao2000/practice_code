# -*- coding: utf-8 -*-
# 这个书的作者写的编号真的很烦人：
# 它标代码段是一段一段 ，而代码文件却是一整个文件
# 一点不符合我们编码的习惯 ，所以我打算取它第一个编码代码段作为编码代码文件名
# 比如 6-7 resize.py  6-8 resize.py 6-9  resize.py 6-10 resize.py其实都是指着 resize.py文件（各个编码代码段）
#  这里我规定 自己 只取第一个 6-7 resize.py  
# 就这样了

import numpy as np
import argparse
import imutils
import cv2

# 构造参数解析器并且解析参数
ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="Path to the image")
# 这个功能太神奇了， 它能够外部导入图片指令，而不需要改变里面的代码
# 拥有代码好的封装性
args = vars(ap.parse_args())


# 加载图片并且显示它
image = cv2.imread(args["image"])
cv2.imshow("Original",image)


# 要注意图像的横纵比 ，这样图像才不会看起来扭曲
# 这里取宽度150个像素点
r = 150.0/image.shape[1]
dim = (150,int(image.shape[0]*r))

# 执行图像处理
resized = cv2.resize(image,dim,interpolation=cv2.INTER_AREA)
cv2.imshow("Resized (Width)",resized)

# 我们想要调整图片的高度，我要记住比率 ratio
# 根据高度计算 比率 
# 让我们将大小调整图像设置成50像素

r = 50.0/image.shape[0]
dim = (int(image.shape[1]*r),50)

# 执行高度大小操作
resized = cv2.resize(image,dim,interpolation=cv2.INTER_AREA)
cv2.imshow("Resized(Height)",resized)
cv2.waitKey(0)

# 我们每次都计算比率是一个非常痛苦事情
# 让我们直接创建一个图像 指定它的高度和宽度
resized = imutils.resize(image,width= 100)
cv2.imshow("Resized via Function",resized)
cv2.waitKey(0)