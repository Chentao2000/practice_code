// 鸡兔同笼问题 
 // 输入 脚数 求最多有几只动物 ，最少几只动物（动物包括鸡和兔子）
//--------------------------------------------------------
// 解析基础 ： 1. 如果输入脚是奇数 则说明没有满足要求答案， 为0
//            2. 如果输入脚是偶数且能被4整除 则最少有N/4 只兔子 ，最多有 N/2 只鸡
//            3.  如果输入脚是偶数能被2整除不能被4整除 ，则有（N-2）/4 只兔子  和 1只鸡 
#include <cstdio>
int main()
{
    int nCases ,nFeets; //鸡脚 兔脚
    
while(scanf("%d",&nCases)!= EOF) // 输入脚数  取脚数，脚数不等于 EOF （奇数）!  
{
    for(int i = 0; i < nCases ; i++)     //  循环 去脚数
    { 
        scanf("%d ",&nFeets);            // 输入数量 
        
        if(nFeets % 4 == 0)                        // 如果脚能被4整除 
            printf("%d%d\n",nFeets/4,/nFeets/2);
        else if(nFeets% 2 == 0 )
            printf("%d,%d\n  ",nFeets/4 + 1, nFeets/2); // 如果 脚能被4整除 +1 脚除2
        else 
            printf("0 0\n");
            
    }
}
}
