import numpy as np
a = np.array([0,1,2,3,4])
b = np.array([2,4,6,8,10])
# 除法 / 余数，
#     // 商变为整数
#     %  取余
#     np.divide 求除
#     np.mod  求余
b /2
b/3
b//3
np.divide(b,a)  # 会报错 书上原文
np.divide(b,2)
 b%3
