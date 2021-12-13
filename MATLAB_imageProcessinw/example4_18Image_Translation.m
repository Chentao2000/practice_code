

    

% 调用函数move 实现对原图像的移动，其实现MATLAB 代码如下
close all;clear ;clc; 
I = imread('leftImage.png');

a =50; b =50;  % 设置平移坐标
J1= move(I,a,b); %移动原图像

a = -50; b = 50;
J2= move(I,a,b);

a = 50; b = -50;
J3= move(I,a,b);

a = -50; b = -50;
J4= move(I,a,b);

figure,
subplot(1,2,1),imshow(J1),axis on;
subplot(1,2,2),imshow(J2),axis on;
figure,
subplot(1,2,1),imshow(J3),axis on;
subplot(1,2,2),imshow(J4),axis on;





