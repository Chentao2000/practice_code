# 想了想 还是注释用中文吧，English - English 有时候可能会不过脑子

from __future__ import print_function
from unittest import result

from matplotlib.pyplot import title
from pyimagesearch.coverdescriptor import CoverDescriptor
from pyimagesearch.covermatcher import CoverMatcher
import argparse
import glob
import csv
import cv2


# 构造参数解析参数
ap = argparse.ArgumentParser()

ap.add_argument("-d", "--db", required=True, help= " path to the book database ")
#  - d 书本数据集
ap.add_argument("-c", "--covers", required=True, help= "path to the directory that contains our book covers ")
# -c  包含我们书籍的目录和封面
ap.add_argument("-q", "--query", required=True, help= " path to the query book cover ")
#  -q 查询书籍的封面 
ap.add_argument("-s", "--sift", required=True, help= " whether or not SIFT should be used")
# 是否 使用 SIFT whether or not 是否

args = vars(ap.parse_args())

# 初始化封面的数据库字典
1
db = { }

# 循环加载数据集
for l in csv.reader(open(args["db"])):
    # 使用 图像 ID 键 更新数据集
    db[l [ 0 ]] = l[1: ]


# 正在使用 BRISK 作为默认参数
useSIFT = args["sift"] > 0
useHamming  = args["sift"] == 0
ratio = 0.7
minMatches =40


# 如果 要 使用 SIFT 那么要更新参数
if useSIFT:
    minMatches = 50

# 初始化覆盖描述符 ，和 覆盖匹配器
cd = CoverDescriptor(useSIFT=useSIFT)

cv = CoverMatcher(cd ,   glob.glob(args["covers"] + "/*.png"),
    ratio = ratio , minMatches= minMatches ,useHamming= useHamming
)

# 加载查询图像，将其转换为灰度，然后提取
#关键点和描述符
queryImage = cv2.imread(args["query"])

gray = cv2.cvtColor(queryImage , cv2.COLOR_BAYER_BG2BGRA)
(queryKps , queryDescs) = cd.describe(gray)

# 尝试将书籍封面与已知道的图像数据库相匹配
result = cv.search(queryKps , queryDescs)


# 查询已显示的封面
cv2.imshow("Query" , queryImage)


# 检查是否查到了结果 
if len(result) == 0 :
    print(" 我没有查到相匹配的封面项")
    cv2.waitKey(0)


# 否则 ，找到匹配项
else: 
    # 循环结果
    for (i , (score , coverPath)) in enumerate(result):
        # 获取书本信息
        (author , title) = db[coverPath[coverPath.rfind("/") + 1:]]
        print("{} , {:.2f}% : {} - {}".format( i  +1 ,score *100 , author , title))

        # 加载最终的图像 并且展示它
        result = cv2.imread(coverPath)
        cv2.imshow("Result ", result)
        cv2.waitKey(0)
