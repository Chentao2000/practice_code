close all;clear all; clc;
I =imread('girl.png');
J= imread('me.png');
I1 = im2bw(I);
J1 = im2bw(J);
H =~(I1|J1);
G = ~(I1&J1);
figure,
subplot(121),imshow(I1),axis on;
subplot(122),imshow(J1),axis on;
figure,
subplot(121),imshow(H),axis on;
subplot(122),imshow(G),axis on;