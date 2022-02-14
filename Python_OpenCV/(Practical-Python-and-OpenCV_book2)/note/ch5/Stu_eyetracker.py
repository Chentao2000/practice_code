# 导入必要的包 
from sys import flags
import cv2 

class EyeTracker:
    def __init__(self, faceCascadePath, eyeCascadePath):
        # 加载图像 和 眼部检测 器
        self.faceCascadePath = cv2.CascadeClassifier(faceCascadePath)
        self.eyeCascadePath = cv2.CascadeClassifier(eyeCascadePath)

    def track(self , image):
        # detect faces in the image and initizliaze the list of 
        # rectangles containing the faces and eyes
        faceRects = self.faceCascadePath.detectMultiScale(image, scaleFactor = 1.1, minNeighbors = 5 , minSize = (30,30) , flags = cv2.CASCADE_SCALE_IMAGE)
        rect =[]

        # loop over the face bounding boxes
        for (fX , fY , fW , fH  ) in faceRects:
            # extrace the face ROI and update  the list of
            # bounding boxes

            faceROI = image[fY :fY  +fH , fX : fX + fW]
            rect.append((fX , fY , fX +  fW , fY + fH))


            # detect eyes in the faces  ROI
            eyeRects = self.eyeCascade.detectMultiScale(faceROI,
				scaleFactor = 1.1, minNeighbors = 10, minSize = (20, 20),
				flags = cv2.CASCADE_SCALE_IMAGE)

            # loop over the eye bounding boxes
            for(eX , eY , eW, eH ) in eyeRects:
                rect.append(
                    (fX + eX , fY + eY ,fX + eX + eW , fY+ eY  + eH)
                )
# return teh rectangles representing bounding 
# boxes around faces and eyes 
        return rect
