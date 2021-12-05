% 例子 5_4 感知器最重要也是最实用的哦那个能，对输入向量进行分类 ，尝试建立一个感知器 模型 ，实现电路中 “或”门的功能
% MATLAB 如下 

P = [0 1 1 1;0 1 0 1 ]; % 输入向量
T = [0 1 1 1]; % 输出向量 
net = newp(minmax(P),1); %建立感知器 
Y= sim(net,P)    %仿真


net.trainParam.epochs = 50; % 设置最大训练步数
net = train(net,P,T);
Y = sim(net,P)
pref = mae(Y - T)

% 经过两次训练 感知器输出到达了目标值 
