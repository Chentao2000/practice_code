from djitellopy import tello
from time import sleep
# 官方的demo 写复杂了，用了线程 和 命令行响应  还有Python 版本变换 
# 这个第三方教程比较简单   但是 有点 问题 就是执行的时候   用 Python3， python2 会不到大疆的库 
me = tello.Tello()
me.connect()
print(me.get_battery())



me.takeoff()
me.send_rc_control(0,50,0,0)
sleep(2)
me.land