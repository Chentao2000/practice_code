# import the necessary packages

# stu....

import cv2

class FaceDetector:
    def __init__(self,faceCascadePath):
        # 加载这面部检测器
        self.faceCascade = cv2.CascadeClassifier(faceCascadePath) 

    def detect(self , image ,scaleFactor = 1.1 ,minNeighbors = 5 , minSize =(30,30)):
        # 检测 detect 人脸在图像上 
        rects = self.faceCascade.detectMultiScale(
            image,
            scaleFactor = scaleFactor,
            minNeighbors = minNeighbors,
            minSize = minSize,
            flag = cv2.CASCADE_SCALE_IMAGE
            # CASCADE 关联 SCALE 比例 IMAGE 图像
        )
        return rects # 返回带有面部框的 图像