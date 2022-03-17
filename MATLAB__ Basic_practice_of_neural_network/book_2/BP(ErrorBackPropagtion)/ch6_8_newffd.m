P = {1 0 0 1 1 0 1 0 0 0 0 1 1 0 0 1};
T = {1 -1 0 1 0 -1 1 -1 0 0 0 1 0 -1 0 1};
net = newfftd(P,T,[0 1],5);
net.trainParam.epochs = 50;
net = train(net,P,T);
Y = net(P)
view(net)