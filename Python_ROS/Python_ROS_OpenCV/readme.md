
ROS——发布摄像头节点并编写opencv图像处理节点（python）

 ： https://blog.csdn.net/qq_45779334/article/details/114044103?spm=1001.2014.3001.5502
 
 ---- 
 
 ROS给各个传感器的数据做了封装 图像也是其中的一种 
 
 ### 引用图像传感器
 
from sensor_msgs.msg import Image

# 发布图像的话题

 image_pub=rospy.Publisher('/image_view/image_raw', Image, queue_size = 1) #定义话题

 
 
