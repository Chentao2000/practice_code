
 1. C++ 是放在了 功能包的 src 文件里，需要编译 更改（CMakeLists.txt），但是如果是python文件，就放在scripts文件里 
 2. （自己新建一个 scripts 放进去 然后给文件 权限 ： 允许程序作为执行权限 ）直接编译然后 rosrun 节点 文件 就好了
 3. python文件名字也可以用tab补全
 4. 在msg消息定义 中 是以分号作为结尾的 ，但是这在python会显示报错，但实际是可以通过 比如：        persion_msg.name = 18;
5. 加入环境变量 

-----
#### Python_Ros  要记住的指令
###### 通用指令
查看话题列表 ：

```html
rosnode list
```
发布话题消息

 1. C++ 是放在了 功能包的 src 文件里，需要编译 更改（CMakeLists.txt），但是如果是python文件，就放在scripts文件里 
 2. （自己新建一个 scripts 放进去 然后给文件 权限 ： 允许程序作为执行权限 ）直接编译然后 rosrun 节点 文件 就好了
 3. python文件名字也可以用tab补全
 4. 在msg消息定义 中 是以分号作为结尾的 ，但是这在python会显示报错，但实际是可以通过 比如：        persion_msg.name = 18;
5. 加入环境变量 

-----
#### Ros  要记住的指令
 1. C++ 是放在了 功能包的 src 文件里，需要编译 更改（CMakeLists.txt），但是如果是python文件，就放在scripts文件里 
 2. （自己新建一个 scripts 放进去 然后给文件 权限 ： 允许程序作为执行权限 ）直接编译然后 rosrun 节点 文件 就好了
 3. python文件名字也可以用tab补全
 4. 在msg消息定义 中 是以分号作为结尾的 ，但是这在python会显示报错，但实际是可以通过 比如：        persion_msg.name = 18;
5. 加入环境变量 

-----
#### Python_Ros  要记住的指令

( 以古月居小海龟为例)

- 查看话题列表

rosnode list
- 查看话题列表
 rosnode list

- 发布话题消息
rostopic pub -r 10 /turtle1/cmd_vel geometry_msgs/Twist "linear: ....  //.. 线速度参数 
- 发布服务请求
rosservice call /spawn "x: 5.0 y: 5.0 theta: 0.0 name: 'turtle3'"   //  (生成了新小海龟名字为turtle3)
- 话题记录 
rosbag record -a -O cmd_record
rosbag play cmd_record.bag

- 查看话题列表

```bash
rosnode list
```


- 发布话题消息

```bash
rostopic pub -r 10 /turtle1/cmd_vel geometry_msgs/Twist "linear: ....  //.. 线速度参数 
```

- 发布服务请求

```bash
rosservice call /spawn "x: 5.0 y: 5.0 theta: 0.0 name: 'turtle3'"   //  (生成了新小海龟名字为turtle3)
```

- 话题记录 

```bash
rosbag record -a -O cmd_record
rosbag play cmd_record.bag
```

---
#### ROS_ 通用版


-  ROS 节点初始化

```bash
rospy.init_node(' the_node_name',anonymous= True)
```

-  创建一个话题

```bash
xxx = rospy.Publisher(' turtle1/cmd_vel',Twist ,queue_size=10)
```

- 发布消息

```bash
 xx_node.publish( xx_msg )
```


-  打印消息：

```bash
- print（" xxx  %d %f %x" ,msg1,msg2,msg3）
- rospy.loginfo(" xxx  %d %f %x" ,msg1,msg2,msg3)
```
- try except pass 写法

```bash
if __name__ == '__main__'
        # 写进主函数的 
        try :   # 判断这个执行文件有没有成功
            velocity_publisher()  
        except  # 没有成功 ROS中断
            rospy.ROSInterruptException:
        pass  # 成功了 通过！
```


    
----
### ROS话题消息
~~- 躲不掉的 整本 ROS21 讲都要熟练使用~~  

自定义话题消息 ： 话题是消息的类
名称 `xxx.msg`

```bash
字符类型 命名
string name
uint8 sex
uint8 age

uint8 unknown = 0
uint8 male = 1
uint8 female = 2

```
##### 初始化消息 :

```bash
person_msg = Person()
person_msg.name =  "Tom";
 person_msg.age  = "18";
 person_msg.sex   = Person.male;
```

#####  发布消息：

首先创建一个发布者的topic ，消息类型为
learning_topic:: `person`

```bash
person_info_pub.publish(person_msg)
发布者.publish（发布消息内容）
```

 #####  接收消息：
创建回调函数（回调函在`订阅者`中经常使用 ，就是把你要订阅的消息通通写在一个函数里 然后在subscriber 函数 （,, xxxx）xxx写入你的回调函数

###### -  回调函数

```bash
def  personiNfoCalback(msg):
  rospy.loginfo("subscribe  xxx info : xxx: %s,		 xxx: %s ", xxx , xxx)
```
###### -  创建订阅者 订阅这个话题

```bash
rospy.Subscriber( " /订阅名 "，话题，回调函数) 
```



### 客户端 Client
- 客户端应该是与服务端相对的 ，服务端提供服务，客户端根据提供的服务发送指令

发现服务 / 创建一个服务客户端 ，链接 /spawm service

```bash
rospy.wait_for_service("/spawn")
```
用try excepct 来检测服务是否连接成功：

```bash
try:
    add_tutrle  = rospy.ServiceProxy('/spawn',spawn)
    # 请求服务调用 ，输入请求数据
    response = add_tutrle(2.0,2.0,2.0,"tutrle2")
    return response.name

except rospy.ServiceException ,e:
    print " Service calll fialed %s " %e
```

### 服务器 Server
创建 服务 Server 实例， 循环等待服务请求， 进入回调函数 
在回调函数中完成服务功能的处理 ，并反馈应答数据 




