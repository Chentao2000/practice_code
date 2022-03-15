>> x = -3:.2.3;
>> x = -3:.2:3;

>> plot(x,x,'o')
>> hold on;
 
>> plot ([0,0],x([8,24]),'^r','LineWidth',4) % 原始数据投射到 Y 轴上
 
>> plot(zeros(1,length(x)),x,'o')
>> grid on
>> title('原始数据')
>> y = logsig(x);
>> figure(2);
>> plot(x,y,'o')
>> hold on
>> plot(zeros(1,length(y)),y,'o')
 
>> plot([0,0],y([8,24]),'^r','LineWidth',4)
>> grid on
>> title('Sigmoid 函数处理之后')
>> 
