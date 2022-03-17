x = -4:.1:4;
y = logsig(x);
% logsig 函数
dy = dlogsig(x,y);
% logsig 函数的导数
subplot(211)
plot(x,y);
title('logsig')
subplot(212);
plot(x,dy);
title('dlogsig')