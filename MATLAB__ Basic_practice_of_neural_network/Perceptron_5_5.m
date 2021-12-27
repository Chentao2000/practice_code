%% 例5-5 要求建立一个感知器 ，对一组存在奇异值的输入向量P 进行分类 
P = [0 0.5 1.1 21;0 0.7 1.3 70];
T = [0 1 0 1];
% 其中 T 表明了向量的分类情况 
% 数中 有一个数字 对其他点的距离很大 ，另外3个点相对比较集中，因此，输入向量中存在奇异值
% MATLAB 代码如下 ：

net = newp(minmax(P),1);
net=newp(minmax(P),1,'hardlim','learnpn');
net.trainParam.epochs = 500;
net = train(net,P,T);
figure;
plotpv(P,T);;
plotpc(net.iw{1},net.b{1});
axis([-2 2 -2 2])