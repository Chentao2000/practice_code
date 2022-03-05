！！ 注意 ：我们只保留 src ，其他的要在本地编译才能运行

先要 把ros包加到环境变量里

1. 打开 .bashrc
```
sudo gedit .bashrc
```

2. 把下面这句加入最后一行 ，记得更换你的包的路径
```
source 你的路径/TelloGO_IMAG/devel/setup.bash
```

更新路径 

```
source ~/.bashrc
```

----
1. 打开一个终端：

```
roscore
```

2. **新打开终端**，运行:

```
rosrun tello_control tello_state.py
```

3. **新打开终端**，运行:

```
rosrun tello_control tello_control.py
```
