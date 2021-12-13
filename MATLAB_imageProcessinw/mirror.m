function OutImage= mirror(InImage,n)
%mirror 函数实现图像镜像变换过程
% 参数 n为1 时，实现水平镜像变换 
% 参数 n为2 时，实现垂直镜像书平变换
% 参数 n为3 时， 实现水平垂直镜像变换
I = InImage;
[M,N,~] = size(I); %获取水平镜像变换 
J = I;
if (n == 1)
    for i= 1:M
        for j=1:N
            J(i,j,:)= I(M-i+1,j,:) ; %n=1 水平镜像
        end
    end
elseif(n==2)
    for i= 1:M
        for j=1:N
            J(i,j,:)= I(i,N-j+1,:) ; %n=2 垂直镜像
        end
    end
elseif (n==3)
    for i= 1:M
        for j=1:N
            J(i,j,:)= I(M-i+1,N-j+1,:) ; %n=3  s水平垂直镜像
        end
    end
    else 
        error('参数n输入不正确，n取值1，2，3')
    end
    OutImage=J;
    

