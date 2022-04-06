p = [-100,100]
t = 1
net = newp(p,t) % 创建一个感知器
P = [-5,-4,-3,-2,-1,0,1,2,3,4] %训练输入
T =[0,0,0,0,0,1,1,1,1,1] % 训练输出
net = train(net,P,T) % 用 train开始训练
newP=  -10:.2:10;
newT = sim(net,newP); %测试输入实际输出
plot(newP,newT,'LineWidth',3);
title('判断数字符号的感知器')
