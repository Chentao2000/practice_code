close all;clear all;clc;
A = imread('house.jpg');
B = immultiply(A,1.5);
C = immultiply(A,0.5);
figure,
subplot(1,2,1),imshow(B),axis on;
subplot(1,2,2),imshow(C),axis on;