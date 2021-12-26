// 说实话 没懂 ！ 等有时间再把它弄懂在来
/******************************************************************************

2. 7 例题 ：排列 

问题描述 ： 给出正整数n 则 1 ~ n 这个n个数可以构成 n！ 种排列，把这些排列按照从小到大的程序
（字典顺序） 列出 ：

如 n = 3 时 列出 123 132 213 231 312 321 六种排列

任务描述 ： 给出某种排列，求出这种排列的下k个排列，如果遇到最后一个排列，则下一排列为第1个排列
则排出  123...n  列如 对于 n = 3 k = 2 给出排列 2 3 1，则它的下一个排列为 3 1 2 
下两个排列为 3 2 1 ，因此 答案 是 3 2 1

输入数据 ：

第一行是一个正整数m，表示测试的数据的个数，后面是m组测试的数据 ，每组测试数据的第一行是两个整数
n （ 1 < n 1024 ） 和  k （ 1 < k < 64） 第二行有n个正整数 ，是 1 ~ n 则它的下一个排列为

输出要求：

对于每组输入数据，输出一行，其中包含n个数，中间用空格隔开，表示输入排列的下k个排列

输入排列 ：
                    3
                    3   1
                    2   3   1
                        
*******************************************************************************/
#include <cstdio>
#include <stdio.h>

int a[1025] = {0};

// 这本书不愧是 北京大学 教材 ，一行程序注释都给 ，那我自己猜着写啦
void NextPermutation(int size){
    int flag = size - 1;
    int temp;
    int i;
    while(a[flag - 1] > a[flag]&&flag!=0){
        flag --;
    }
    
    if(flag == 0){
        for (int i = 0; i < size; i++) {
            a[i] = i + 1;
            return;
        }
    }
    // ↑ 这个应该是顺着循环 把数组标号的数 等于实际的数 如 a[1] = 1
    
    
    for (int i = size - 1 ; i < size; i++) {
        if(a[i] > a[flag - 1]){
            temp = a[flag - 1];
            a[flag - 1] = a[i];
            a[i] = temp;
            break;
        }
    }
    
    while(size - 1 > flag){
        temp = a[size - 1];
        a[size - 1] = a[flag];
        a[flag] = temp;
        flag ++;
        size --;
    }
}

int main(void){
    int m ,n ,k;
    int i;
    scanf("%d",&m);
    while(m){
        
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (int i = 0; i < k; i++) 
        NextPermutation(n);
    for (int i = 0; i < n; i++) 
        printf("%d",a[i]);
    
        printf("\n");
    m--;
    }

    return 0;
}
