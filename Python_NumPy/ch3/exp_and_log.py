# 指数函数和对数函数 e （纳皮尔常数）的x 次方
# 对数函数：只有那些使用特殊底的函数提供了支持
# e : np.log(x) 数学上： logeX = lgx
# 2 : np.log2(x) 而numpy 中 默认 e为底
# 10 : np.log10(x)
# 1+x : np.log1p(x)
np.exp(1)
np.exp(2)
np.exp(0)
np.log(np.e)
a = np.array([1.,2.,np.e**2,10])
np.log(a)
b = np.array([1.,2.,4.,7])
np.log2(b)
c = np.array([1.,10.,20.,100])
np.log10(c)
np.log1p(a)
# 如果需要把底改成其他值，可以将这个需要改变的底数除以作为实数的对数
# logx（y） = loge(y） / loge(x)
# 即 log4（2） = loge(2） / loge(4)
np.log(2)/np.log(4)  # log4(2)可以使用这个代码实现 4 为 底
np.log(9)/np.log(3)
