close all; clear ;clc;
A = imread('icon-lib-energy-storage.png');
B = imread('icon-lib-vehicle-scenario.png');
C = immultiply(A,B); % 计算A 和B 的乘法 结果返回C
A1 = im2double(A);
B1 = im2double(B);
C1 = immultiply(A1,B1);% 转换成双精度重新返回 C
figure,
subplot(121),imshow(A),axis on;
subplot(122),imshow(B),axis on;
figure,
subplot(121),imshow(C),axis on;
subplot(122),imshow(C1),axis on;
