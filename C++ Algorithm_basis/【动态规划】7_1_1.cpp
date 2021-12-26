// 动态规划 ；
// 第 4 章 用递归方法 解决某些问题时候效率会很低，例如数组三角形
//                    7
//                 3    6
//               8    1   0
//             2   7    4  4
//            4   5   2  6   5
// 上面给了一个数字三角形 ， 从三角形顶部到底部有多少条路径 对于每条路径数加起来得到一个和
#include <iostream>
#include <cstdio>
using namespace std;
// 输入数据 ：
// 第一行是一个整数 N （1 < N < 100）给出三角形的行数
// 下面 用 N行 给出数字三角形，数字三角形中的数的范围 在 0~100 之间

// 输出要求 ： 输出最大的和
// 输出样例 30

// program 7.1.1 cpp
#define MAX_NUM 100
int d[MAX_NUM + 10][MAX_NUM + 10];
int N;
// 这道题目可用递归的方法解决，基本思路是 ： 以D（r,j)表示第r行，第j个数字，（r，j）
// 都可以从1开始算，以Maxsum 代表第r 行 的第j个数字到底边的最佳路径的数字之和，则从题目开始要求MAXSum（1，1）
//  从某个D(r,j)开始 ，显然下一步只能走 D(r+1，j)或D（r+1，j+1）那么得到的是 MaxSum（r，j）
// 所以选择从哪走，就需要比较MAXSum（r+1，j）和MaxSum（r+1，j+1）哪个值最大
int MaxSum(int r, int j)
{
    if (r == N){
        return d[r][j];
    int sum1 = MaxSum(r + 1, j);
    int sum2 = MaxSum(r + 1, j + 1);
    }

    if (sum1 > sum2)
    {
        return sum1 + d[r][j];

        return sum2 + d[r][j];
    }
}
int main(void)
{
    int m;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            scanf("%d", &d[i][j]);
        }
        printf("%d", MaxSum(1, 1));
        
    }
    return 0;
}
