% 运用减法运算实现混合图像分离
% 实现MATLAB
close all;clear all; clc;
A = imread('tire.tif');
[m,n]=size(A);
B = imread('eight.tif');
C = B;
A = im2double(A);
B = im2double(B);
C = im2double(C);
for i = 1 :m
    for j =1:n
            C(i,j)= B(i,j)+ A(i,j);
    end
end
D = imabsdiff(C,B);
figure,
subplot(121),imshow(A);
subplot(122),imshow(B);
figure,
subplot(121),imshow(C);
subplot(122),imshow(D);
