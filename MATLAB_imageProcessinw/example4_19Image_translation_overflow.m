close all;clear ; clc;
I = imread('leftImage.png');
a=50;b=50;
J1 = move_plus ( I,a,b);

a= -50;b=50;
J2 = move_plus ( I,a,b);

a=50;b= -50;
J3 = move_plus ( I,a,b);

a= -50;b= -50;
J4 = move_plus ( I,a,b);

figure,
subplot(1,2,1),imshow(J1),axis on;
subplot(1,2,2),imshow(J2),axis on;
figure,
subplot(1,2,1),imshow(J3),axis on;
subplot(1,2,2),imshow(J4),axis on;