% 利用函数 imcomplement() 实现图像矩阵和数据矩阵的求补运算
J = imread('rice.png');
J1 =im2bw(J);
J2 = imcomplement(J);
J3 = imcomplement(J1);
figure,
subplot(131),imshow(J1);
subplot(132),imshow(J2);
subplot(133),imshow(J3);