# -*- coding: utf-8 -*-
import numpy as np
import argparse
import cv2



ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
	help = "Path to the image")
args = vars(ap.parse_args())



# 加载图片并且显示它 
image = cv2.imread(args["image"])
cv2.imshow("Original",image)


# 构件一个150 x 150 的面罩 区该住它

mask = np.zeros(image.shape[:2],dtype="uint8")
(cX,cY) = (image.shape[1]//2,image.shape[0]//2)
cv2.rectangle(mask,(cX - 75,cY -75),(cX+75,cY+75),255,-1)
cv2.imshow("Mask",mask)


# 只有中心矩形区域显示
maksed = cv2.bitwise_and(image,image,mask=mask)
cv2.imshow("Mask Applied to Image",masked)
cv2.waitKey(0)



# 现在 如我做一个原型面罩
mask = np.zeros(image.shape[:2], dtype = "uint8")
cv2.circle(mask, (cX, cY), 100, 255, -1)
masked = cv2.bitwise_and(image, image, mask = mask)
cv2.imshow("Mask", mask)
cv2.imshow("Mask Applied to Image", masked)
cv2.waitKey(0)
