1. 不是我啥都学一点，是因为真的有很长的技术链要走... 学就完事了 ！！！！
2. 突然想学一下欧拉角 旋转矩阵 以及四元数的， 看了很多都不清楚，或者不知道重点，刚好看见高翔老师这里第三章讲的很详细，所以突发奇想
刚好一起学了 所以就开了 哈哈哈哈 
-----

# ch3 : 
### 编译准备
用 josn文件配置太麻烦 ，直接VSCODE 插件 ：C/C++ Compile Run 安好之后 按 F6 编译运行 （记得开了Fn键）
然后 安装 eigen 库 ： 
sudo apt-get install libeigen3-dev

- 当调用 eigen 库时，会报错：fatal error: Eigen/Core: No such file or directory
- 这是因为 eigen 库默认安装在了 /usr/include/eigen3/Eigen 路径下，需使用下面命令映射到 /usr/include 路径下
挂上软链接 ：

sudo ln -s /usr/include/eigen3/Eigen /usr/include/Eigen
