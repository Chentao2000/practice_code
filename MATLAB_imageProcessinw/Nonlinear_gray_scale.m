close all;clear ;clc;
R = imread('peppers.png');
G = rgb2gray(R);
J = double(G);
H= (log(J+1))/10;
figure,
subplot(121),imshow(G);
subplot(122),imshow(H);
