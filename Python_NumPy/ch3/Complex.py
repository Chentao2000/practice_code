# 复数 ： Numpy 也提供对复数的支持 只需要在 虚部添加 J 即可 
#  四元数：四元数是对复数进行扩展后得到的概念，是由一个实部和三个虚部所构成，在对三维空间的物体进行旋转表示中经常用到
# np.real 返回实部 np.imag 返回 虚部  np.conj 返回共轭复数 （虚部取反）
import numpy as np
a = 1 + 2j
b = -2 + 1j # 不要忘写1 
np.real(a)
np.imag(a)
a + b 
a * b
a / b
np.conj(a)
