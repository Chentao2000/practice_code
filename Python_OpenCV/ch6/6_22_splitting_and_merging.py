import  numpy as np
import argparse 
# 构造解析函数 包？ 外部导入图片的包
import cv2
# 用恐龙做这个真的看不出什么


ap = argparse.ArgumentParser()
ap.add_argument("-i","--image",required=True,
help = " Path to the image")
args = vars(ap.parse_args())



# 加载图像 并且抓取每一个通道

image = cv2.imread(args["image"])

(B,G,R) = cv2.split(image)   #numpy 把它倒过来了 ，正确排序应该是 RGB
# 这个函数应该是把它 R G B 分离出来


cv2.imshow("Red",R)
cv2.imshow("Green",G)
cv2.imshow("Blue",B)
cv2.waitKey(0)


# 重新合并图像

merged = cv2.merge([B,G,R]) # Numpy 是倒的 
cv2.imshow("Merged",merged)
cv2.waitKey(0)
cv2.destroyAllWindows()


# 现在我们以每个颜色显示通道
zeros = np.zeros(image.shape[:2],dytpe = "uint8")
cv2.imshow("Red",cv2.merge([zeros,zeros,R]))
cv2.imshow("Rred",cv2.merge([zeros,G,zeros]))
cv2.imshow("Blue",cv2.merge([B,zeros,zeros]))

cv2.waitKey(0)