/******************************************************************************

递归 ：
4.2  例题 汉诺塔问题
- 输入数据 ：
        
        汉诺塔内盘子个数 n（1 <= n <= 64 ）

- 输出要求 ：
    
        输出移动的步骤，每行动一步，如从A座移动到B座，输出 A -> C

----------------------------------------------------
解题思路：
    
        可以用递归的思路来分析，即把原问题分解成一个或多个形式相同，但规模会小一些问题：
    结果会发现，把A座上n个盘子通过B座中移动到C座，可以分为以下三个步骤：
    
    1） 将A座上的n-1盘子以C座为中转，移动到B座
    2） 将A座最下面的一个盘子移动到C座
    3） 把B座上n-1个盘子以A座为中转，移动到C座
    
    据此 可以写出使用递归函数的解题步骤：
*******************************************************************************/

// example 42

#include <iostream>
using namespace std;

// src min dest
// 将src座上的n个盘子以mid座为中转，移动到dest座
void Hanoi(int n,char src,char mid,char dest){
    if(n == 1) //只需要移动一个盘子
    {
        //  直接将盘子从src移动到dest即可
        cout << src<<" -> "<< dest << endl;
        return;
    }
    // 先将 n - 1 个盒子从src移动到mid
    Hanoi(n-1,src,dest,mid);
    //再将一个盘子从src移动到dest
    std::cout << src<<" -> "<<dest << std::endl;
    //最后将n-1个盘子从mid移动到dest
    Hanoi(n-1,mid,src,dest);
    return;
}

int main(){
    int n ;
    std::cout << "请输入盘子的个数" << std::endl;
    cin>>n;
    Hanoi(n,'A','B','C');
    return 0;
}









