###function approximation f(x)=sin(x)
###激活函数用的是sigmoid
import numpy as np
import math
import matplotlib.pyplot as plt
import pylab as pl
import mpl_toolkits.mplot3d

x = [-13.84, 10.69, 28.88, 47.05, 65.19, 83.36, -13.49, 9.32, 26.34, 43.12, 76.82,  -10.80, 7.54, 24.84, 42.05, 59.25, 76.38,  -9.72, 23.87, 41.21, 58.58, 75.87,  -8.62, 4.86, 21.84, 38.7, 56.32, 73.75, -7.72, 3.72, 21.25, 38.6, 55.56]
xmax = np.max(x)
xmin = np.min(x)
x = (x - xmin)/(xmax - xmin)
y = [27.64, 26.95, 26.43, 25.92, 25.45, 24.94, 34.41, 33.93, 33.47, 32.93, 31.91,  37.76, 36.92, 36.44, 35.97, 35.39, 35.09,     54.88, 52.87, 52.41, 51.93, 51.55,  65.77, 64.79, 63.84, 62.91, 61.99, 61.06,  86.12, 84.94, 83.78, 82.65, 81.55]
ymax = np.max(y)
ymin = np.min(y)
y = (y - ymin)/(ymax - ymin)
[X, Y] = np.meshgrid(x, y)

##  归一化处理 .....

# print(x)
# print(x[1])
x_size = 33
y_size = 33
z = [0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 5, 0, 1, 2, 3, 4, 5, 0, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4]
zmax = np.max(z)
zmin = np.min(z)
z = (z - zmin)/(zmax - zmin)
hidesize = 15  # 隐层数量
W1x = np.random.random((hidesize, 1))  # 输入层与隐层之间的权重
W1y = np.random.random((hidesize, 1))  # 输入层与隐层之间的权重
B1 = np.random.random((hidesize, 1))  # 隐含层神经元的阈值
W2 = np.random.random((1, hidesize))  # 隐含层与输出层之间的权重
B2 = np.random.random((1, 1))  # 输出层神经元的阈值
threshold = 0.007  # 阈值（槛值）
max_steps = 400  # 迭代最高次数，超过此次数即会退出


def sigmoid(x_):  # 这里x_和y_在函数里面，不需要改
    y_ = 1 / (1 + math.exp(-x_))
    return y_


E = np.zeros((max_steps, 1))  # 误差随迭代次数的变化
Z = np.zeros(x_size)  # 模型的输出结果
for k in range(max_steps):
    temp = 0
    for i in range(x_size):
        hide_in = np.dot(x[i], W1x) + np.dot(y[i], W1y) - B1  # 隐含层输入数据
        # print(x[i])
        hide_out = np.zeros((hidesize, 1))  # 隐含层的输出数据
        for m in range(hidesize):
            # print("第{}个的值是{}".format(j,hide_in[j]))
            # print(j,sigmoid(j))
            hide_out[m] = sigmoid(hide_in[m])  # 计算hide_out
            # print("第{}个的值是{}".format(j, hide_out[j]))

            # print(hide_out[3])
        z_out = np.dot(W2, hide_out) - B2  # 模型输出

        Z[i] = z_out
        # print(i,Y[i])

        e = z_out - z[i]  # 模型输出减去实际结果。得出误差

        # 反馈，修改参数
        dB2 = -1 * threshold * e
        dW2 = e * threshold * np.transpose(hide_out)
        dB1 = np.zeros((hidesize, 1))
        for m in range(hidesize):
            dB1[m] = np.dot(np.dot(W2[0][m], sigmoid(hide_in[m])), (1 - sigmoid(hide_in[m])) * (-1) * e * threshold)
            # np.dot((sigmoid(hide_in[j])), (1 - sigmoid(hide_in[j])))为sigmoid(hide_in[j])的导数
        dW1x = np.zeros((hidesize, 1))
        dW1y = np.zeros((hidesize, 1))

        for m in range(hidesize):
            dW1y[m] = np.dot(np.dot(W2[0][m], sigmoid(hide_in[m])), (1 - sigmoid(hide_in[m])) * y[i] * e * threshold)
        W1y = W1y - dW1y
        for m in range(hidesize):
            dW1x[m] = np.dot(np.dot(W2[0][m], sigmoid(hide_in[m])), (1 - sigmoid(hide_in[m])) * x[i] * e * threshold)
        W1x = W1x - dW1x
        B1 = B1 - dB1
        W2 = W2 - dW2
        B2 = B2 - dB2
        temp = temp + abs(e)

    E[k] = temp

    if k % 2 == 0:
        print(k)

# 反归一化
x = x * (xmax - xmin) + xmin
y = y * (ymax - ymin) + ymin
z = z * (zmax - zmin) + zmin
Z = Z * (zmax - zmin) + zmin
print(x)  # 输出输入的自变量x，即U_p
print(z)  # 输出输入的z
print(Z)  # 输出拟合的Z
# draw the figure, the color is r = read
print('e:')
print(E)
# 误差函数图直接上面两个函数值Y和y相减即可。

# 测试集误差计算
xtest = np.array([59.99, 6.56, 73.28])
xtest_size = 3
ytest = np.array([32.47, 53.97, 80.45])
ztest = np.array([4, 1, 5])
# 测试集输入元素归一化
xtest = (xtest - xmin)/(xmax - xmin)
ytest = (ytest - ymin)/(ymax - ymin)
e_test = 0
ztest_out = np.zeros(3)
for i in range(xtest_size):
    hide_in = np.dot(xtest[i], W1x) + np.dot(ytest[i], W1y) - B1  # 隐含层输入数据
    # print(x[i])
    hide_out = np.zeros((hidesize, 1))  # 隐含层的输出数据
    for m in range(hidesize):
        # print("第{}个的值是{}".format(j,hide_in[j]))
        # print(j,sigmoid(j))
        hide_out[m] = sigmoid(hide_in[m])  # 计算hide_out
        # print("第{}个的值是{}".format(j, hide_out[j]))

        # print(hide_out[3])
    ztest_out[i] = np.dot(W2, hide_out) - B2  # 模型输出
    e_test = e_test + abs(ztest_out[i] - ztest[i])  # 计算训练集均方误差
xtest = xtest * (xmax - xmin) + xmin
ytest = ytest * (ymax - ymin) + ymin
ztest_out = ztest_out * (zmax - zmin) + zmin
e_test = np.dot(ztest_out - ztest, ztest_out - ztest)
print('ztest_out:')
print(ztest_out)
print('e_test:')
print(e_test)

# 绘图
plt.figure()
plt.xlabel("generation")
plt.ylabel("error")
plt.title('hidesize = 15,max_steps = 200')
plt.plot(E, color='blue', linestyle='--')
plt.show()
