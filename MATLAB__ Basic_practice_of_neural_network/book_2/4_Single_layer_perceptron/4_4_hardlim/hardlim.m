figure;
subplot(2,1,1);
n = -5:0.01:5;
plot(n,hardlim(n),'LineWidth',2); %hardlim 函数值
subplot(2,1,2);
plot(n,hardlims(n),'r','LineWidth',2) % hardlim函数值
subplot(2,1,1);
title('hardlim');
