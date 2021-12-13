close all;clear all; clc;
R = imread('peppers.png'); % 读入原图像，赋值给R
J = rgb2gray(R);  % 将彩色图像数据R转换成J
[M,N]=size(J); % 获得灰色图像的行和列（M,N）用作便利用
x =1; y =1;
%% 为了突出图像中感兴趣的目标，对图像进行分段式的变换
%%
for x= 1:M
    for y = 1:N
        if(J(x,y)<= 35) %对灰度图像数据J 进行变换，处理好的结果发回给矩阵
            H(x,y)=J(x,y)*10;  
        elseif (J(x,y)>35 && J(x,y))
            H(x,y)=(10/7)*[J(x,y)-5]+50;
        elseif(J(x,y)>75)
            H(x,y)=(105/180)* [J(x,y)-75]+150;
        end
    end
end
figure,
subplot(121),imshow(J);
subplot(122),imshow(H);
%% 三段变换法其实选定一个区间 ，利用这个区间相差乘以相加运算
%% 本算法中 选取区间是 a= 35  b= 75 而灰度值再 0 -255之间... 
%% 以最后的计算为例  c = 350  d = 360  Gmax = 465 Fmax = 255

            