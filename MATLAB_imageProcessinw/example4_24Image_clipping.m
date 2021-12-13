close all;clear all;clc;
[A,map] = imread('me.png'); %读入图像
rect  = [75 68 130 112]; % 定义剪切区域
X1 = imcrop(A,rect);
subplot(121).imshow(A);
% rectangle('Position',rect, 'LineWidth',2,'EdgeColor','r');
% subplot(122),imshow(X1); % 显示切割后图像
