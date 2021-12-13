% imsubtract 从一个图像中减去另一个图像
close all;
clear all;
clc;
A = imread('cameraman.tif');
B = imread('testpat1.png');
C = imsubtract(A,B);
figure,
subplot(121),imshow(C);
subplot(122),imshow(255-C);
