# USAGE
# python train.py --dataset data/digits.csv --model models/svm.cpickle

# import the necessary packages

from statistics import mode
from string import digits
import joblib
from numpy import var
from sklearn.svm import LinearSVC
from pyimagesearch.hog import HOG
from pyimagesearch import dataset
import argparse

ap = argparse.ArgumentParser()
ap.add_argument("-d" ,  "--dataset" ,required= True , help= " path to tehe dataset file")
ap.add_argument("-m" , "--model",required=True,help="path to where to the model will be stored")
args = vars(ap.parse_args)




# 加载数据集，并初始化数据矩阵
(digits , target) = dataset.load_digits(args["dataset"])
data = []

# 初始化 HOG 数据集
hog = HOG(orientations=18 ,pixelsPerCell= (10,10), cellsPerBlock=(1,1), transform= True)


# 循环遍历图像

for image in digits:
    # 歪斜图像 ，居中
    image = dataset.deskew(image , 20)
    image = dataset.center_extent(image , (20,20))


    #描述图像并更新数据矩阵 
    hist = hog.describe(image)
    data.append(hist)

# 训练这个模型
model = LinearSVC(random_state=42)
model.fit(data,target)

# 存储这个文件
joblib.dump(model ,args["model"])




