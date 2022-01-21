1. 不是我啥都学一点，是因为真的有很长的技术链要走... 学就完事了 ！！！！
2. 突然想学一下欧拉角 旋转矩阵 以及四元数的， 看了很多都不清楚，或者不知道重点，刚好看见高翔老师这里第三章讲的很详细，所以突发奇想
刚好一起学了 所以就开了 哈哈哈哈 
3. 数学那部分我真的好难 ： 算啦算啦，我知道怎么做就好了，等我学好了数学再来做！
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
sudo ln -s /usr/local/bin/Plotter /usr/include/Plotter
https://blog.csdn.net/qq_38364548/article/details/121700327?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164273478816780264012364%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164273478816780264012364&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-121700327.first_rank_v2_pc_rank_v29&utm_term=%2Fusr%2Flocal%2Finclude%2Fpangolin%2Fgl%2Fgl.hpp%3A+In+member+function+%E2%80%98void+pangolin%3A%3AGlTexture%3A%3ACopyFrom%28const+pangolin%3A%3AGlTexture%26%29%E2%80%99%3A+%2Fusr%2Flocal%2Finclude%2Fpangolin%2Fgl%2Fgl.hpp%3A334%3A5%3A+error%3A+%E2%80%98glCopyImageSubDataNV%E2%80%99+w&spm=1018.2226.3001.4187
