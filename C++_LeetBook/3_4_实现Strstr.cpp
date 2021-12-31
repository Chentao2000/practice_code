/******************************************************************************

字符串匹配算法 KMP

实现 strStr()
实现strStr()函数。

给你两个字符串haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。




说明：

当needle是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当needle是空字符串时我们应当返回 0 。这与 C 语言的strstr()以及 Java 的indexOf()定义相符。

*******************************************************************************/
class Solution {
public:
    int strStr(string haystack, string needle) {
        // 取两个字符串
        int m = needle.length() , n = haystack.length();
        // 一个 字符串命名 为 m， 另一个 字符串命名为 n
        if(!m)return 0;
        // 如果 m 为 0  取反为真 则返回 0 
        vector <int> next(m , 0);
        // C++ 啊这 就涉及到我的知识盲区了
        //这个 是 下一个 为  0?
        next[0] = -1;
        
        int j = -1;
        for(int i = 0 ; i < m - 1 ; i++) {
            while(j >= 0 && needle[j] != needle[i])
            j = next[j];
            // 如果不等 ，就跳到下一个
            j++;
            next[i + 1] = j;
            // ......
        }
        j = 0;
        for(int i = 0 ; i < n ; i++) {
            while(j >= 0 && haystack[i] != needle[j])j = next[j];
            j++;
            if(j == m)return i - m + 1;
        }
        return -1;
    }
};

// 大概懂把 ，这是一个遍历的方式
