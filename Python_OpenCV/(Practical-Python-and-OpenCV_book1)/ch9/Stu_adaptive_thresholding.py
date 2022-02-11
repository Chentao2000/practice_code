import  numpy as np
import argparse
import cv2


ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,help="Path to the image")
args = vars(ap.parse_args())



# 加载图像 ，转回（convert）灰色空间  稍微(slightly)模糊一下（blur）
image = cv2.imread(args["image"])
image = cv2.cvtColor(image , cv2.COLOR_BGR2GRAY)
blurred = cv2.GaussianBlur(image , ( 5, 5),0)
cv2.imshow("Image",image)


# 在以前的（previous）例子中 ，我们使用了手动的（manually）具体指定 （specify）一个 像素值
# 去作为全局阈值 ，在这个例子中 我们将检查 examin 一个相邻的 像素值 和 自适应地 应用（apply）
# 每个邻居像素的阈值，在这里例子中 ，我将要计算（calculate）这相邻区域的11个像素值的平均值 （the mean value）
# 最终 我们的常数将在平均值之间被减去 


thresh = cv2.adaptiveThreshold(blurred , 255,cv2.ADAPTIVE_THRESH_MEAN_C , cv2.THRESH_BINARY_INV,11,4)
cv2.imshow("Mean Thresh",thresh)


# 我们可以以同样的方式应用高斯( Gaussian )阈值 

thresh = cv2.adaptiveThreshold(blurred , 255 , cv2.ADAPTIVE_THRESH_GAUSSIAN_C , cv2.THRESH_BINARY_INV,15,3)
cv2.imshow("Gaussian Thresh ",thresh)
cv2.waitKey(0)




