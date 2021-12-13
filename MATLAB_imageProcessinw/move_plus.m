function J = move_plus(I,a,b)
% 定义一个函数名字 move ，I 表示输入图像
% a 和 b 描述I 图像 沿着I图像 沿着x轴 和y轴移动的距离
% 考虑平移以后图像溢出的情况，采用扩大显示区域的方法
[M,N,G] = size (I); % 获取输入图像I的大小
I = im2double(I); % 将图像数据类型转换成双精度
for i =1:M 
    for j = 1:N
        if(a<0 && b<0 )  % 如果进行右下移动，将新图像矩阵进行赋值
            J (i,j,:)= I(i,j,:); 
        else if (a>0 && b>0 )
             J(i+a,j+b,:)= I(i,j,:);
         else if (a>0 && b<0)
             J(i+a,j,:)=I(i,j,:);
           else if (a<0 && b>0)   
            J(i,j+b,:)=I(i,j,:);
               end
             end
            end
        end
    end
end

            