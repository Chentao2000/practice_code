clc 
clear all
close all

disp('A Star Path Planning start !!')

p.start = [10,1];
p.goal = [1,10] ; 



p.XYMAL = 11;

obstacle = GetBoundary(p); %边界数据

nObstatcle = 50;
obstacle = GetObsacle(nObstatcle ,obstacle , p );
path = AStar(obstacle , p);
figure(1)

if length(obstacle) >=1
    plot(obstacle(:,1),obstacle(:,2),'om');hold on;
end

plot(p.start(1),p.start(2),'*r');hold on;
plot(p.goal(1),p.start(2),'*b');hold on;
% ↑ 画线函数...

if length(path)>=1
    plot(path(:,1),path(:,2),'-r');hold on;
end







