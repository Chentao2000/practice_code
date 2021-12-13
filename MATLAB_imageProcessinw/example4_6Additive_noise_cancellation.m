close all;clear all;clc;
RGB = imread('eight.tif');
A = imnoise(RGB,'gaussian',0,0.05); % 加入高斯白噪声
I = A;
M = 3;
I = im2double(I);
RGB = im2double(RGB);
for i = 1:M
        I=imadd(I,RGB);
end
avg_A=I/(M+1);
figure,
subplot(121);imshow(A);
subplot(122);imshow(avg_A);