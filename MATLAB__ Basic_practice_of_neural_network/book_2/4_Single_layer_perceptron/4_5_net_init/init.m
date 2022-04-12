%%观察感知器权值的变化
net = newp([0,1;-2,2],1) %创建感知器
net.iw{1,1}              %创建值的权值
net.b{1}                  %创建时的偏置
P = [0,1,0,1;0,0,1,1]     %训练输入向量
T = [0,0,0,1]               %训练输入向量的期望输出
net = train(net,P,T)        %训练
net.iw{1,1}                 %训练后的权值
net.b{1}                %初始化的偏置
net.initFcn             %net.initFcn值
net.initParam           % 当net.initFcn = initlay 时

