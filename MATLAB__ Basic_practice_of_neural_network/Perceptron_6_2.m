%% 设计自适应线性网络 ，实现从矢量到输出矢量的变换关系 ，其输入矢量和输出矢量分别如下：
P = [1.0,-1.2]
T = [0.5,1.0]
%% 学习自适应线性网络解决问题 设计者要确定期望误差值 ，以及最大循环次数，自适应网络MATLAB代码如下所示
P = [1 -1.2];
T = [0.5 1];
[R ,Q]= size(P);
[S ,Q]= size(T);
[W ,B]= rands(S,R);
max_epoch = 20; % 最大循环次数 
err_grol = 0.001 ;%期望误差
lr = 0.4*maxlinlr(P);%最佳学习速率
disp_frep = 1;%设置显示频率
TP = [disp_frep max_epoch err_grol lr]; % 设置参数TP
[W, B, epochs , error] = tranwh(W,B,P,T,TP) %进行线性网络权值训练
