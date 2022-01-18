


 1. C++ 是放在了 功能包的 src 文件里，需要编译 更改（CMakeLists.txt），但是如果是python文件，就放在scripts文件里 
 2. （自己新建一个 scripts 放进去 然后给文件 权限 ： 允许程序作为执行权限 ）直接编译然后 rosrun 节点 文件 就好了
 3. python文件名字也可以用tab补全
 4. 在msg消息定义 中 是以分号作为结尾的 ，但是这在python会显示报错，但实际是可以通过 比如：        persion_msg.name = 18;
5. 加入环境变量 
6. msg 中不能用tab !!
7. 引入自定义好的话题消息时候，form 节点.msg  import 消息名称 ，而不是 form 消息名称.msg （虽然你消息名称是 消息名称.msg） ！！！
8. 一个python文件只能初始化 一个节点 
9. 定义一个变量之前也要先使用 glabal 申明一下变量，不要不明不白就去使用了，虽然python 可以直接 = 不会报错
10. 线程的使用方法：
```python
        self.con_thread = threading.Thread(xxxx = xxxx)
        self.con_thread.start()
```
11. 文件名和类名不要重叠 ，会找不到定义的
12. 节点只初始化一次 ，但是话题消息却是一直在发布

-------------------------------
13. C++  和 Python 代码的转换：

ROS中 Python 没有句柄的 ，python 赋值时候就本身就是句柄了 C++ 要新建一个 句柄

还有就是 C++ 中初始化一个msg 要  这样子
```bash
void xxx(const geometry_msgs::PoseStamped::ConstPtr &msg)
```
而 python 只要
```bash
def xxx(msg):
```
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

`编译消息的步骤：`

1. 打开 package.xml 添加依赖 （添加到最下面）

```bash
<build_depend>message_generation</build_depend>
<exec_depend>message_runtime</exec_depend>
```

2.  在CMakelist 添加编译依赖项:

在功能包里添加  message_generation

```bash
find_package( ...... message_generation)  
```

找到注释 找到你要添加的 msg 

```bash
add_message_files(
FILES 
xxx.msg )
generate_messages(
DEPENDENCIES
 std_msgs)
catkin_msg
 
```

然后在catkin package 里直接去掉注释 ，加入 message_runtime 

```bash
catkin_package(...... message_runtime)
```


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

1. 创建命令行线程：
```bash
def command_thread():
		while 判断条件（）：
			if pubCommand：
					vel_msg = Twist() #从Twist这个msg调用这个消息
					vel_msg .linear.x =0.5
					vel.msg.linear.y = 0.2 
					turtle_vel_pub.publish( 发布消息 vel_msg)
			time.sleep(0.1)
```


2. 创建命令行 回调函数：

```bash
def comandCalllback(req):
	  gloal xxx   // 声明变量
# 显示请求数据
		rospy.loginfo("xxxx %d",xxx)   // 答应出来
# 反馈数据
		return TriggerResponse(1,"Change turtle command state !") #反馈数据
	  
```

3. 创建turtle命令行服务器：

```bash
def turtle_command_server():
		# ROS节点初始化：
		rospy.init_node("xxx ") # xxx 是节点的名字
		# 创建一个 / xxx 的 服务 ，注册回调函数 commandCallback
		s = rospy.server('/turtle_command',Trigger,commandcallback)
	# 循环等待回调函数 ：
		print "Read to receive turtle_server"

```
4.  线程开启

```bash
 thread.start_new_thread(command_thread,())
```
---- 
### 参数的使用和方法 rosparam
参数模型 是一个全局字典
##### 参数命令
列出当前多个参数
```bash
rosparam list
```
显示某个参数值:
```bash
rosparam get /xxx # paramkey
```
设置某个参数值

```bash
 rosparam set xxx  xxx # paramkey paramvalue
```
保存参数到文件 

```bash
 rosparam dupm xxx # flie_name
```

从文件中读取参数
```bash
 rosparam load xxx # flie_name
```
删除参数
```bash
 rosparam delete xxx # param_key
```

##### 获取和设置参数：

1. 初始化一个ROS节点：
 

```bash
rospy.init_node('xxx', anoymous =True)
```
2.  get 函数 获取参数  set 函数设置参数

```bash
def xxx () 主函数
 # 获取参数
  xxx  = rospy.get_param('')
  xxx =  rospy.set_param('')
 #  打印出来你获取参数
 rospy.logifo( " %d %d ",xxx xxx)
 
# 设置参数
  xxx = ros.set_param(" ")
  xxx = ros.set_param(" ")
 #  建议你设置出来打印参数
 rospy.logifo( " %d %d ",xxx xxx)
# 再获取一遍 确保你获取成功了
  xxx  = rospy.get_param('')
  xxx =  rospy.set_param('')
 #  打印出来你获取参数
 rospy.logifo( " %d %d ",xxx xxx)
```

3.  使用try excerpt 函数 确保你连接服务成功

```bash
# 首先 发现服务 ，创建一个服务客户端. 连接的 xxx 的 服务
rospy.wait_for_serive ('/clear')
try :
		clear_background = rospy.ServiceProxy('/clear',empty)
		# ↑ ↓清除一下原先的数据！ 不清除 没法用
		response = clear_background()
		return response
except  rospy.ServiceExcepct ,e :
		print " 服务请求失败"
```

4 . 主函数发布程序

```bash
xxxx main xxx
 		xxx () 主函数

```



-----
