/******************************************************************************
 第五章 二分查找 
 
 5 _3 在线翻译 
 
输入数据 ： 输入包含不多于 1000 000 条词语，接着空一行 ，然后是待翻译的短文
            包含不多于 1 000 000 个外语单词，每一个词占一行，包含英语单词 和对应的外语单词，两者要用空格隔开
            短文中每个外语单词占一行，输入保证没有重复的外语单词，且每个单词都由不多于10个
            的小写字母组成
            
输出要求 ： 输出是翻译成·英文的短文，每个英文单词占一行，如果有的词典没有出现
            外语单词，则该单词应该被翻译成 eh
            
输入样例 ：dog ogday
           cat atcay
           pig igpay
           froot ootfray
           loops oopslay
           
输出样例： cat
           eh
           loops
           
*******************************************************************************/
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct Entry
{
    char ENG[11];//English
    char FOG[11];//外语Foreign
}entry1[100005];
int Cmp(Entry a,Entry b)
{
    return strcmp(a.FOG,b.FOG)<0;
}

void binarySearch(Entry entry1[100005],int n,char word[])
{
    int mid,L=0,R=n-1;
    int f=0;
    while(R>=L)
    {
        mid=L+(R-L)/2;
        f=strcmp(entry1[mid].FOG,word);
        if(f<0)
            L=mid+1;
        else if(f>0)
            R=mid-1;
        else if(f==0)
        {
            printf("%s\n",entry1[mid].ENG);
            break;
        }
    }
         if(f!=0) printf("eh\n");
}


int main()
{
    //freopen("Text.txt","r",stdin);
   int n=0;
   while(1)
   {
       scanf("%s%s",entry1[n].ENG,entry1[n].FOG);
       n++;
       cin.get();
       if(cin.peek()=='\n') break;
   }
   sort(entry1,entry1+n,Cmp);
   char word[11];
   while(~scanf("%s",word))
   {
       binarySearch(entry1,n,word);

   }
   return 0;
}
