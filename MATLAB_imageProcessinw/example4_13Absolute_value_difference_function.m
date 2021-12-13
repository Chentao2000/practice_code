% 利用函数imabsdiff 实现图像举证 何数据矩阵的绝对值差
close all;clear ;clc;
i = imread('calibrated_together.png');%对图像矩阵进行滤波
J = filter2(fspercial('prewitt'),I); %求滤波后的图像与原图像绝对值差
K = imabsdiff(double(I),J);
figure,
subplot(131),imshow(I);
subplot(132),imshow(J,[]);
subplot(131),imshow(k,[])
X = [255 10 75;44 255 100];
Y = [50 50 50 ; 50 50 50];
X1 = uint8([255 10 75;44 255 100]);
Y1 = uint8([50 50 50 ; 50 50 50]);
z = imabsdiff(X,Y);
Z1 = abs(X-Y);
Z2 = abs(X1 - Y1);
disp('Z与Z1 比较结果:'),Z_Z1=(Z==Z1);
