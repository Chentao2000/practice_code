%% 例题 5-8 用两层感知器神经网络来实现异或函数 
%% 解： 异或真值表 见表
%  输入P1   输入 P2     输出 y
%   0         0          1
%   1         0          1
%   0         1          1
%   1         1          0

clear all;
clc
%%%%%%%  第一层感知器 初始化
PR1 = [0 1; 0 1];
net1 = newp(PR1, 4);
net1.inputweights{1}.initFcn='rands';
net1 = init(net1);
IW1 = net1.iw{1};
B1 = net1.b{1};


%%%%%%%%%%%%%% 第一层感知器 的机器仿真

P1 = [0 0 ; 0 1;1 0;1 1]';
[A1, Pf]= sim(net1,P1);

%%%%%%%%%%%%%%%%  第二层感知器的初始化  %%%%%%

PR2 = [0 1;0 1;0 1;0 1];
net2 = newp(PR2,1);

%%%%%%%%%   训练第二层感知器：

net2.trainParam.epochs =500;

net2.trainParam.show =5;
P2 = ones(4,4);
P2 = P2.*A1;
T2 = [0 1 1 0];
[net,TR2]= train(net2,P2,T2);
epoch2 = TR2.epoch;
perf2 = TR2.perf;
IW2 =net2.iw{1};
B2 = net2.b{1};














