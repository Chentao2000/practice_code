# USAGE
# python detect_faces.py --face cascades/haarcascade_frontalface_default.xml --image images/obama.png


from __future__ import print_function
from matplotlib.pyplot import gray
from pyimagesearch.facedetector import FaceDetector
#  from 文件名.文件 import 它的类
import argparse
import cv2


#构件两个参数
ap = argparse.ArgumentParser()
ap.add_argument("-f", "--face ",required= True,help="path to where the face cascade resides")
ap.add_argument("-i", "--image", required = True,help = "path to where the image file resides")
args = vars(ap.parse_args())

# 转换成灰度图像 
image = cv2.imread(args["image"])
grav = cv2.cvtColor(image , cv2.COLOR_BGR2GRAY)

# 找到这个图像在脸部中 
fd = FaceDetector(args["face"])
faceRects = fd.detect(gray, scaleFactor = 1.1, minNeighbors = 5,
	minSize = (30, 30))
print(" i find {} face(s)".format(len(faceRects)))

# 在面上循环 并在面上画上一个矩形 
for (x ,y ,w, h)  in faceRects:
    cv2.rectangle ( image , (x,y) , (x  + w, y+h),(0,255,0),2)

cv2.imshow("Faces",image)
cv2.waitKey(0)

