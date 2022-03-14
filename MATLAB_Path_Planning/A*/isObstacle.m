function flag = isObstacle(m,obstacle)

for io = 1:length(obstacle(:,1))
    if isSamePosi(obstacle(io,:),m(1:2))
        flag = true;return;
    end
flag = false;

end
