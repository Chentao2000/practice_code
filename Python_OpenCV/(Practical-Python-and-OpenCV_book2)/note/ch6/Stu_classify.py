# USAGE
# python classify.py --model models/svm.cpickle --image images/umbc_zipcode.png

# import the necessary packages
from __future__ import print_function
from urllib.error import ContentTooShortError
from cv2 import CHAIN_APPROX_SIMPLE
import joblib
from pyimagesearch.hog  import HOG
from pyimagesearch import dataset
import argparse
import mahotas
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-m" , "--model",required=True,help= "path to where the model will be stroed")
ap.add_argument("-i","--model",required=True,help= "path to the image file ")

args = vars(ap.parse_args)

# 加载这个 模型
model = joblib.load(args["model"])

# 初始化这个 HOG 的标识符

hog = HOG(orientations= 18, pixelsPerCell= (10,10), cellsPerBlock=(1,1) , transform= True)


# 加载这个图像 ，并且转换成灰度
image = cv2.imread(args["image"])
gray = cv2.cvtColor(image,cv2.COLOR_BAYER_BG2GRAY)


# 模糊图像 ，找到边缘，并且找到轮廓
# 边缘区域

blurred = cv2.GaussianBlur(gray, (5,5) , 0)
edged = cv2.Canny(blurred , 30 ,150)
(cnts,_) = cv2.findContours( edged.copy() , cv2.RETR_EXTERNAL , cv2,CHAIN_APPROX_SIMPLE)



# 按 x轴 的顺序进行排序 ，确保我们阅读的数据是从左到右
# sort the contours by their X-axis position ，ensuring that we read the number  from left on right
cnts = sorted([ c ,cv2.boundingRect(c)[0]  for c in conts   ] , key = lambda x:x[1] )


# loop over the contours
for (c,_) in cnts:
    # 计算每个方格的正方形大小
    (x , y ,w ,h ) = cv2.boundingRect(c)

    # 如果高宽都至少 7 个像素
    #  至少是20个像素，轮廓至少像一个数字
    if w >= 7 and h >= 20:
        #


