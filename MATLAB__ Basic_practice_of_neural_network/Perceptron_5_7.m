%% 例5_7 给定样本输入向量P,目标向量 T 以及需要进行分类的输入向量M，设计一个单层感知器 对其进行分类 
clear all
clc
P = [0.5 -1 2;-0.8 1.3 1]
T = [1 1 0];
net = newp([-1 1;-1 1],1);  %建立单层感知器网络 
h = plotpc(net.iw{1},net.b{1}); %返回画线的句柄
net.trainParam.epochs = 50 ;% 设置训练次数最大为50
net=train(net,P,T);            %训练神经网络
%%%%%%%%%%%%%%%%%%% 用训练后的感知器网络仿真 %%%%%%%%%%%%%%%%%%%%%
M = [0.5 1.1 -0.2 ; -0.2 -0.6 0.6];
Y = sim(net,M);
figure
plotpv(M,Y); %绘制分界线 
h = plotpc(net.iw{1},net.b{1},h)