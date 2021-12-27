/******************************************************************************

 4 _4 棋盘分割：
 问题描述 ：
 
 将一个 8 x 8 的棋盘进行如下分割，将原棋盘割下一块矩形棋盘并使剩下部分也是矩形
 再将剩下部分继续如此分割，这样分割  n - 1 次后，连同最后剩下的矩形棋盘共有n块矩形棋盘
 （每次切割都只能按照棋盘格子的边进行）

原来棋盘每一格 有一个分值，一块矩形棋盘总分为 其所含各格分值之和，现在需要将棋盘按照上述规则
分割成 n 块 矩形棋盘，并使得各矩形棋盘总分的均方差最小


输入数据 ： 
第一行 为一个整数 n （ 1 < n < 15）
第 2 ~  9 行 ，为 8个 小于 100 的非负整数 ，表示棋盘上相应格子的分值 ，每行相邻两数之间用一个空格分隔

输入 要求 ：
仅仅一个数 ，为 - （四舍五入精确小数点后三位）
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>

using  namespace std;
int s[9][9];
// 每个格子的分值
int sum[9][9];
//  ( 1, 1) 到 （ i , j ）的矩形的分数之和
int res[15][9][9][9][9];
// fun 的记录表

int CalSum(int x1,int y1,int x2 ,int y2){
    // (x1 ,y1) 到 ( x2 , y2) 的矩形的分数之和
    return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1- 1][y1- 1];
    
}

int min(int a,int b){
    return a < b ? a:b;
}


int Fun (int n, int x1 ,int y1 ,int x2,int y2){
    int temp,i,j,cut,remain,MIN = 10000000;
    if(res[n][x1][y1][x2][y2] != -1)
        return res[n][x1][y1][x2][y2];
    if(n == 1){
        temp  = CalSum(x1,y1,x2,y2);
        res[n][x1][y1][x2][y2] = temp * temp;
        return temp* temp;
    }
    for ( i = x1; i < x2; i++) {
        // 沿着 x 方向切
        cut = CalSum( i + 1,y1,x2 ,y2);
        remain = CalSum(x1,y1,i,y2);
        temp = min(Fun(n - 1,x1,y1,i,y2) + cut*cut , Fun(n - 1,i + 1,y1,x2,y2) + remain*remain);
        if(MIN > temp)MIN = temp;
        res[n][x1][y1][x2][y2] = MIN;
        return MIN;
    }
}
    int main(){
        memset(sum , 0 ,sizeof(sum));
        memset(res,-1,sizeof(res));
        
        int n ;
        cin >> n;
        for (int i = 0; i < 9; i++) {
            for (int j = 1,rowSum = 0;j<9; j++) {
                
                cin >> s[i][j];
                rowSum += s[i][j];
                sum[i][j] += sum[i-1][j] + rowSum;
                
                //以积分图形式计算子块和，便于 CalSum计算
                double result = n* Fun(n,1,1,8,8) - sum[8][8] * sum[8][8];
                std::cout << setiosflags(ios::fixed)<<setprecision(3)<<sqrt(result/(n*n)) << std::endl;
                return 0;
            }
        }
    }













