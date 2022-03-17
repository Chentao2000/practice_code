BP 神经网络 ：

# 引言：

- 线性神经网络只能解决线性可分问题 ， BP神经网络是包含多个隐含层网络，具备处理不可分问题的能力
- 感知器、线性神经网络、BP网络与径向基神经网络都属于前项网络


`
其中 BP 网络和径向基神经网络都属多层前向神经网络
`
----- 

## newff 创建一个 BP 网络：



newff 是BP网络中最常用的函数，可以用于创建一个误差反向传播的前向网络，再 MATLAB R211b 中：
语法如下：


###  net = newff(P,T,S)
- 输入参数 P: P x Q1 矩阵，表示创建的神经网络中，输入层有 R 个神经元，每行代表的是输入数据的典型值，实际应用中常取它的最大最小值
- 输入参数 T: SNxQ2 矩阵，表示创建的网络有 SN 个输出层节点，每行是输出值的典型值
- 输入参数 S: 标量和矢量 ，用于制定隐含层神经元个数，若隐含层多于一层，则写成行向量形式。


输出参数 如下 ：
- 返回一个length（S1） 层，（不包括输入层）的BP神经网络



### net = newff(P,T,S,TF,BTF,BLF,PF,IPF,OPF,ODF)
- TF(i): 第i层的传输函数，隐含层默认为tansig，输出层默认为 purelin
- BTF:  BP网络的训练函数，默认值为 trainlm，表示采用 LM 法进行训练
- BLF: BP网络的权值和阈值函数，默认为 learndm
- PF : 性能函数，默认值为mse，表示采用均方误差作为误差训练函数
- IPF：指定输入数据归一化函数的细胞数组，默认值为{‘fixunknowns’, 'remoconstanrows','mapminmax'} 
(其中 mapminmax 用于正常数据的归一化，fixunknowns 用于含有缺失数据时的归一化)
- OPF: 指定输出数据的反归一化函数，用细胞数组形式表示，默认值为{‘remconstantrows , 'mapmaxmin'’}
- DDF : 数据划分函数，newff函数将训练数据分为三份，可以用来防止出现过拟合请阔


### net = newff(P, N, TF, BTF) （旧版）
- 旧版 省略


## feedforwardnet - 创建一个BP网路：
`
  feedforwardnet(hiddenSzies,trainFcn)
`

- hiddenSizes 为隐含层的神经元节点个数，如果有多个隐含层，则hiddenSizes是一个行向量，默认值 为10；
- trainFcn 为训练函数，默认值为' hrainln ' 
- feedforwardnet 函数未确定输入层和输出层向量的维数，系统将这一步留给 train 函数完成，也可以使用configure函数手动配置
- feedforwardnet 函数实现前向神经网络能够实现输入到输出函数的任意映射，用于拟合的函数 fitnet 和 用于 模式识别的函数 patterennet 均为 feedforwardnet 的不同版本

- 使用默认的参数feedforwardnet 函数训练一个神经网络 ，观察网络的参数




## 比较 cascadeforwardnet - 新版级联前向网络
-  在级联BP 神经网络中，每一层除了接收上一层提供的出入外，还得到其他层提供的权值连接
![1647485283(1)](https://user-images.githubusercontent.com/68007558/158726543-50b7d340-1836-4c42-8419-6561e4789970.jpg)


### newffd  -   前反馈输入延迟的BP网络：
- newffd 用于创建一个带输入延迟的网络， 函数语法如下
`
net = newfft(P,T,ID .....)
`
除了ID之外，newffd的参数大部分与newff函数相同，ID表示输入延迟的向量，默认为[0,1]




### dlogsig/dtansig_Sigmoid函数的导数：

....


















