# 5.1
import numpy as np
import cv2
from numpy.core.defchararray import center

canvas = np.zeros((300, 300, 3), dtype = "uint8")

# R G B ( R , G , B ) t = (B , G . R)
#  5.2
green = (203,192,255)
cv2.line(canvas,(0,0),(300,300),green)
cv2.imshow("Canvas",canvas)

red = (0,0,255)
cv2.line(canvas,(300,0),(0,300),red,3)
cv2.imshow("Canvas",canvas)
cv2.waitKey(0)

# 5.3
cv2.rectangle(canvas,(10,10),(200,225),red,5)
cv2.imshow("Canvas",canvas)
cv2.waitKey(0)

blue = (255,0,0)
cv2.rectangle(canvas,(200,50),(225,125),blue,-1)
cv2.imshow("Canvas",canvas)
cv2.waitKey(0)

# 5.4 drawing.py
canvas = np.zeros((300,300,3),dtype="uint8")
(centerX,centerY) = (canvas.shape[1]//2,canvas.shape[0]//2)
white= (255,255,255)

for r in range(0,175,25):
    cv2.circle(canvas,(centerX,centerY),r,white)

cv2.imshow("Canvas",canvas)
cv2.waitKey(0)

#  5.5 drawing.
for  i in range(0,25):
    radius = np.random.randint(5,high=200)
    color = np.random.randint(0,high=256,size=(3,)).tolist()
    pt = np.random.randint(0,high=256,size=(2,))
    cv2.circle(canvas,tuple(pt),radius,color,-1)

cv2.imshow("Canvas",canvas)
cv2.waitKey(0)
