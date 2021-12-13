close all;clear all ;clc;
gamma =0.5;
I = imread('peppers.png');
R = I;

% X( : : X) 其中x 置于1 2 3 表示R G B 三个元素 
R(:,:,2)=0;
R(:,:,3)=0;
R1 = imadjust(R,[0.5,0.8],[0,1],gamma);
%利用函数 imadjust（）调整R的灰度值 ，结果返回 1

G = I;
G(:,:,1)=0;
G(:,:,3)=0;
G1 = imadjust(G,[0 0.3],[0 ,1],gamma);


B = I;
B(:,:,1)=0;
B(:,:,2)=0;
B1 = imadjust(B,[0 0.3],[0 ,1],gamma);

I1 = R1+ G1 +B1;

figure;
subplot(121),imshow(R);
subplot(122),imshow(R1);

figure;
subplot(121),imshow(G);
subplot(122),imshow(G1);


figure;
subplot(121),imshow(B);
subplot(122),imshow(B1);




