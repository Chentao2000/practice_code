% 图像除法运算 是 给出两幅图像相应像素值的变换比率
% 而不是每个像素绝对差异，图像除法也称为比率变换 常用于成像设备的非线性影响
close all; clear all;clc;
I = imread('office_1.jpg');
J = imread('office_2.jpg');
Ip = imdivide(J,I);
K = imdivide(J,0.5);% 图像和一个常数相除
figure,
subplot(121);imshow(I); 
subplot(122);imshow(J);
figure,
subplot(121);imshow(Ip);
subplot(122);imshow(K);

