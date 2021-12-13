 clear ;clc;
I = imread('cameraman.tif');

 J1 = mirror(I,1);
 J2 = mirror(I,2);
 J3 = mirror(I,3);
 
 
 figure,
 subplot(1,2,1),imshow(I); %绘制原图像
 subplot(1,2,2),imshow(J); %
  figure,
 subplot(1,2,1),imshow(J2); %绘制原图像
 subplot(1,2,2),imshow(J3); %