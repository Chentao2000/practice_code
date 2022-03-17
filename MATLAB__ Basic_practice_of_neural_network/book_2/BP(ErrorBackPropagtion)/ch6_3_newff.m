%% newff 逼近二次函数，新版函数的误差要比旧版的函数大
x = -100:.5:100;
y = x.^3;
net = newff(minmax(x),minmax(y),10);
net = train(net,x,y);
xx = -100:.5:100;
yy = net(xx);
plot(x,y,'o-',xx,yy,'*-')
title('新-旧版newff')
hold on;

%% 👇? 为旧版创建的
net1 = newff(minmax(x),[10,1],{'tansig','purelin'},'trainlm');
net1 = train(net1,x,y);
yy2 = net1(xx);
figure(2);
plot(x,y,'o-',xx,yy2,'*-')
title('新-旧版newff')

%% 实测中 旧神经网络在大量数据中表现并不好，根本无法逼近收敛