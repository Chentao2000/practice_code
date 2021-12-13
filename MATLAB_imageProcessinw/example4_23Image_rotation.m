% 图像的旋转 属于图像位置的变换 ，通常是以图像中心为原点
% 图像上所有的像素旋转一个相同的角度，旋转后图像大小一般是会改变
close all;clear all;clc;
A = imread('grid.jpg');
J1 = imrotate(A,30);
J2 = imrotate(A,-30);
J3 = imrotate(A,30,'bicubic','crop');
% 设置输出图像大小 ，实现旋转图像并显示
J4 = imrotate(A,30,'bicubic','loose');
% 显示旋转处理结果
figure,
subplot(121),imshow(J1);
subplot(122),imshow(J2);
figure,
subplot(121),imshow(J3);
subplot(122),imshow(J4);