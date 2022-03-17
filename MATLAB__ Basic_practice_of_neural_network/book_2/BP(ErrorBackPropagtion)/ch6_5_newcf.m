[x,t] = simplefit_dataset; % MATLAB自带数据，x ,t 均为 1*94 的向量
 net = feedforwardnet; % 创建前向网络
 view(net);
 net = train(net,x,t);
 % 训练 确定 输入和输出向量的维度 
 view(net)
 y = net(x);
 perf = perform(net,y,t)
 perf