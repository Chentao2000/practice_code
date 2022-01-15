 1. C++ 是放在了 功能包的 src 文件里，需要编译 更改（CMakeLists.txt），但是如果是python文件，就放在scripts文件里 
 2. （自己新建一个 scripts 放进去 然后给文件 权限 ： 允许程序作为执行权限 ）直接编译然后 rosrun 节点 文件 就好了
 3. python文件名字也可以用tab补全
 4. 在msg消息定义 中 是以分号作为结尾的 ，但是这在python会显示报错，但实际是可以通过 比如：        persion_msg.name = 18;
5. 加入环境变量 



 ```
 class Tello:
    """Wrapper class to interact with the Tello drone."""

    def __init__(self, local_ip, local_port, imperial=False, command_timeout=.3, tello_ip='192.168.10.1',
                 tello_port=8889):
 echo "source (Path To YourWorkSpace)/devel/setup.bash" >> ~/.bashrc
 source ~/.bashrc
 ```
