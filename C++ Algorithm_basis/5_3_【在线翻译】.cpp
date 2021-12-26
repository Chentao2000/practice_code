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

// 有几个报错 真不知道怎么解决了 ，cin 找不到！
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
struct Entry{
    char english[11];
    char foreign[11];
}entries[100005];


// 自定义的cmp函数
int Cmp(Entry entry1,Entry entry2){
    return strcmp(entry1.foreign,entry2.foreign)<0;
}

int main(){
    int num = 0;
    char word[11];
    while(true){
        scanf("%s %s",entries[num].english,entries[num].foreign);
        num++;
        cin.get();
        if(cin.peek()== '\n')break;
    }
    sort(entries,entries+num,Cmp);
    while(scanf("%s",word)!= EOF){
        int left = 0 ,right = num - 1;
        int n = 0;
        while(left <= right){
            int mid = left + (right - left)/2;
            n = strcmp(entries[mid].foreign,word);
            if(n < 0 )left = mid + 1;
            else if(n > 0)right = mid - 1;
            else {
                printf("%s\n",entries[mid].english);
                break;
            }
        }
        if(n)printf("eh\n");
    }
    return 0;
}
