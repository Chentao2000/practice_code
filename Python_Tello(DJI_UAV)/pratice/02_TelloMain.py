from djitellopy import Tello
import cv2
import time


width = 320
height = 240
startCounter = 0



me = Tello()
me.connect()
me.for_back_velocity = 0
me.left_right_velocity = 0
me.up_down_velocity = 0
me.yaw_velocity = 0
me.speed = 0


print(me.get_battery)

me.streamoff()
me.streamon()
# 这个无人机运行时候会报一堆错误 ，这是因为信号传输的问题 ：
# 但是我们还是有必要记录和翻译一下这些报错（以便和我们自己程序报错区别开来）：
# 1. non-existing PPS 0 referenced

# 2. decode_slice_header error

#  3. no frame!

# 4.  left block unavailable for requested intra mode

# 5 . error while decoding MB 0 11, bytestream 6433

# 6.  error while decoding MB 0 20, bytestream 4319

# 7.  error while decoding MB 50 39, bytestream -9


while True:
    frame_read = me.get_frame_read()
    myFrame = frame_read.frame
    img = cv2.resize(myFrame,(width,height))

    if startCounter == 0:
        me.takeoff()
        time.sleep(8)
        me.rotate_clockwise(90) #顺时钟
        time.sleep(3)
        me.move_left(35)  
        time.sleep(3)
        me.land()
        startCounter = 1

    cv2.imshow("Myimage",img)

    if cv2.waitKey(1)&0xFF == ord('q'):
        me.land()
        break
