% 调用函数 Denosie 观察叠加次数对消除噪声及程序执行时间影响

close all;clear all;clc;
RGB = imread('eight.tif');
M1 =3 ;
[BW1,runnight1]= Denoise(RGB,M1);
M2 =9 ;
[BW2,runnight2]= Denoise(RGB,M2);
figure,
subplot(121);imshow(BW1);
subplot(122);imshow(BW2);
disp('叠加4次运行时间');
runnight1
disp('叠加10次运行时间');
runnight2_