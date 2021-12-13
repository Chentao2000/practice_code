I = imread('me.png');
H = imread('National_Flag.png');
K = I/2 + H/2; figure,
subplot(121),imshow(H),
subplot(122),imshow(K),
