/******************************************************************************

2 _ 5 约瑟夫 问题：

    问题描述 ： 有 n 只猴子 ，按顺时针方向围成一圈选大王，（编号从 1 到 n）
            从 第 1号开始报数 ，一直数到 m ,数到 m的猴子退出圈外，剩下的猴子
            再接着从 1 开始报数 ，就这样，直到圈内只剩下一直猴子时间，这个猴子就
            是个猴王
            
            编程输入 n 和m 输出最后猴王的编号

解析思路 ： 
    这个问题很难通过数学推导 找到一个合适的解析解：因此 采用算法求解这问题时，
    一个简单的方法就是模拟该过程，将n个数排成一圈，然后从 1开始数，每数到m个就
    划掉一个数，一遍遍做下去，直到剩下最后一个数
    
    编程实现时，用一个数组存放n个数，用一个整形变量指向数组的某一个位置，表示当前应当退出的猴子
    退出的操作，可以使用将一个全 0 数组元素 置 1 的方式来实现，循环查找下一个位置时候
    计数的过程需要跳过已经置 1 的元素，为了模拟圈圈，当正兴变量指向数组的最后一个位置
    下一步需要指向数组的第一个元素，以实现循环的效果
    
*******************************************************************************/
#include <cstdlib>
#include <cstdio>

int flag[1000000005];
void init(){
    for (int index = 0; index < 305; index++) {
        flag[index] = 0;
    }
}
int main(){
    int n , m;
    scanf("%d",&n);
    scanf("%d",&m);
    while( n != 0 && m != 0){
        int index = -1;
        int count = 0;
        init(); //全部没有数过
        for (int i = 1; i < n; i++) {
            count = 0;
            while(count != m){
                index = (index + 1)%n;// 到圈尾，取模
                if(flag[index]==0){
                    // 如果还没有出去圈，累加数量
                    // 如果累加到m，该位置的点退出圈，置 1开始数
                    count ++ ;
                    if(count == m)
                    {
                        flag[index] = 1;
                    }
                }
            }
        }
            // 打印出最后未出圈的点：
    for (int j = 0; j < n; j++) {
        if(flag[j] == 0){
            printf("%d\n",j+1);
            break;
        }
    }
    scanf("%d",&n);
    scanf("%d",&m);
    }


return 0;
}
