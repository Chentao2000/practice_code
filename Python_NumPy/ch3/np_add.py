import numpy as np
a = np.array([0,1,2,3,4])
b = np.array([2,4,6,8,10])

print (a + b) # OUT 1
print(a + 4) # OUT 3
# 使用 np.add()也是同样效果
print (np.add(a,b))# OUT 3
print (np.add(a,4)) # # OUT 4
