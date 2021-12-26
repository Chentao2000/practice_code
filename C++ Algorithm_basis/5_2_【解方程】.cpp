/******************************************************************************
 第五章  ： 二分查找
 
 5.2 . 例题 ：方程求解：
 
    求下面方程的根： f（x） = x3 - 5x2 + 10x - 80 = 0
                     ( x3 是指 x 的三次方 ↑ 以上同理) 
 
 输出要求 ： 精确在小数点后 9位
 
 输出样例： 5.705085930
 
 解题思路 :  对于 f（x）求导 ： 得到 f（x)` = 3x2 - 10x + 10 
            由于 f（x）`  = 0 无解 ，因此 f（x)` > 0 恒成立
        一元三次方程f（x）关于x 都是单调递增的 ，且 f （0） = - 80 < 0
        而 f（10） =520 >0 ,则根必在 【0 10】 之间
        所以可以用二分查找的方法在区间【0 10】 寻找根
        
        二分查找 的具体方法是 ：每次在寻找区间 【left right】取中点 mid = reft + （right - left）
        作为假定的根，计算f（mid） 分为以下三种情况处理：
        
        （1）若f（mid）> 0 则根必然在【left right】中间，于是令 right = mid ，在新的区间中寻找根
        （2）若f (mid）< 0 则根必然在 【mid right】中间，于是令 left = mid ，在新的区间中间寻找根
        （3）若f（mid）- 0 小于题目要求的精度范围，则mid就有要求近似的根
        
        由此可以看见二分查找的一个应用：此时mid就是要求求解的近视的根
*******************************************************************************/

#include <cstdio>
#include <cmath>
using namespace std;
double BinarySearch(double left,double right){
    double mid;
    double f;
    while(right - left > 1e-11){
        // 其实不明白这个 1e-11 是什么？ 
        mid = left + (right - left)/2;
        f = mid * mid * mid - 5*mid*mid + 10*mid - 80;
        if( f < 0)
            left = mid;
        else 
            right = mid;
    }
    return mid;
}

int main(){
    printf(" %.9lf \n",BinarySearch(0.0,10.0));
    return 0;
}
