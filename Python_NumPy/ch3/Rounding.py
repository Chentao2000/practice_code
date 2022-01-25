import numpy as np
a = np.array([-1.8 , 1.4 , -1.0 , -0.6, -0.2,0.,0.2,0.6,1.0,1.4,1.8])
np.floor(a) # 向下取整  取值比其 小的整数
np.trunc(a) # 向下 取整， 舍弃小数
np.ceil(a) # 向上取整
np.around(a)  # 四舍五入
np.rint(a) #四舍五入
np.round(a)  # 四舍五入
np.fix(a)# 取最接近 0 的数
