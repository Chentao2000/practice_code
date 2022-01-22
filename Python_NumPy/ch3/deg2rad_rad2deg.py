# 弧度和角度的转换 180度 = pi
# np.rad2deg  弧度 → 角度
# np.deg2rad  角度 → 弧度
np.radians(120)
np.deg2rad(120)
np.rad2deg(3.14)
np.deg2rad(np.rad2deg(2.3))
# 接下来对  radians 和 deg2rad 换算速度进行比较
%timeit np.radians(24)
%timeit np.deg2rad(24)
#  明显看出deg2rad更快
