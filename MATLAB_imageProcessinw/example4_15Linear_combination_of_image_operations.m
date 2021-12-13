close all;clear all;clc;
I = imread('cameraman.tif');
J = imread('rice.png');
K1 = imlincomb(1.0,I,1.0,J);
K2 = imlincomb(1.0,I,-1.0,J,'double');
K3 = imlincomb(2,I);
K4 = imlincomb(0.5,I);

figure,
subplot(121),imshow(K1);
subplot(122),imshow(K2);
figure,
subplot(121),imshow(K3);
subplot(122),imshow(K4);