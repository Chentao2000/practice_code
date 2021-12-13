function J = move(I,a,b)
% 定义一个函数名字move I表示输入图像
% a 和 b描述I 图像沿着 x轴 和  y轴移动的举例
% 不考虑平移以后 图像溢出的情况 ，找不到对应点的地方都赋值为1
[M,N,G] = size(I); % 获取输入图像I的大小 
I = im2double(I); % 将图像转化成 类型 双精度
J = ones(M,N,G); % 初始化新图像矩阵全为1 大小与输入图像相符

for i = 1 : M
    for j = 1: N 
        if((i+a) >= 1 && (i+a <= M)&&(j+b >= 1)&&(j+b <= M))
            % 判断平移后是否超过图像的范围 
            J(i+a,j+b,:)=I(i,j,:);
        end
    end
end