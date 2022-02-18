import numpy as np
import cv2

class RGBHistograms:
    def __init__(self,bins):
# 存储直方图 他们使用的个数
        self.bins = bins
    



    def describe(self , image ,mask = None):
        # 在RGB颜色中计算色彩空间
        # 然后归一化直方图，使得图像内容相同，但缩放比例更大
        # 或者更小，将具有更大相同的直方图
            hist = cv2.calcHist([image] , [ 0 ,1,2] , mask , self.bins, [ 0 ,256, 0 ,256,0,256])
            cv2.normalize(hist, hist)



            # 作为一个扁平数组格式返回一个3D直方图 
            return hist.flatten()
