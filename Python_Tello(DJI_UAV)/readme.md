端口被以及占用怎么办：

- 学习网址 ：https://github.com/murtazahassan/Tello-Object-Tracking
- 教学视频 ： https://www.bilibili.com/video/BV11X4y1N7cQ?spm_id_from=333.999.0.0

lsof -i :8000


用到的功能包有：

roscpp rospy sensor_msgs std_msgs

```
catkin_create_pkg ocar_tello roscpp rospy sensor_msgs std_msgs
```

官方的 tello.py 参考
 ```
 class Tello:
    """Wrapper class to interact with the Tello drone."""
    def __init__(self, local_ip, local_port, imperial=False, command_timeout=.3, tello_ip='192.168.10.1',
                 tello_port=8889):
                 
绑定到本地IP/端口并将Tello置于命令模式。
param local_ip（str）：要绑定的本地ip地址。
param local_port（int）：要绑定的本地端口。
param imperial（bool）：如果为真，则速度为英里/小时，距离为英尺。
如果为False，则速度为KPH，距离为米。
param command|u timeout（int | float）：等待命令响应的秒数。
param tello_ip（str）：tello ip。
param tello_port（int）：tello端口。
```
----
配置环境变量
 ```
 source ~/.bashrc
 echo "source (Path To YourWorkSpace)/devel/setup.bash" >> ~/.bashrc

```
-----
