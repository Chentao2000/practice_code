# -*- coding: utf-8 -*-
import numpy as np
import cv2


# 首先 画上一个正方形

rectangle = np.zeros((300,300),dtype="uint8")
cv2.rectangle(rectangle,(25,25), (275,275),255,-1)
cv2.imshow("Rectangel",rectangle)


# 然后 我们画个圆圈

circle = np.zeros((300,300),dtype="uint8")
cv2.circle(circle,(150,150),150,255,-1)
cv2.imshow("Circle",circle)


# AND 与 运算  
# 两个 为真的 就是真的
# 其余都是假的 
# 假的的代表  0 表示黑色
bitwiseAnd = cv2.bitwise_and(rectangle,circle)
cv2.imshow("AND",bitwiseAnd)
cv2.waitKey(0)


# OR 或 运算 
# 两个有一个是真的就是真的
# 与上同理
bitwiseOr = cv2.bitwise_or(rectangle, circle)
cv2.imshow("OR", bitwiseOr)
cv2.waitKey(0)



# Xor  是or 的相反例： 
# 两个有一个是真的 那就是假的
bitwiseXor = cv2.bitwise_xor(rectangle, circle)
cv2.imshow("XOR", bitwiseXor)
cv2.waitKey(0)


# Not 是 AND 相反 例
# 两个都是真的 ，那就是假的
bitwiseNot = cv2.bitwise_not(circle)
cv2.imshow("NOT", bitwiseNot)
cv2.waitKey(0)
