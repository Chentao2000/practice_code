close all;clear;clc;

[X,map] = imread('trees.tif');

J1 = imresize(x,0.25);
J2 = imresize(x,3.5);
J3 = imresize(x,[64,40]);

J4 = imresize(x,1.6,'billinear');
