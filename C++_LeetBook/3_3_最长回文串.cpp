/**
最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。
示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：

输入：s = "cbbd"
输出："bb"

示例 3：

输入：s = "a"
输出："a"

示例 4：
输入：s = "ac"
输出："a"

提示：

    1 <= s.length <= 1000
    s 仅由数字和英文字母（大写和/或小写）组成

**/

// 回文中心法：
class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0, j = 0;
        for(int k=1; k<s.size(); k++)
        {
            int i0 = k, j0 = k;//奇数回文
            while(i0>0 && j0<s.size()-1)
            {
                if(s[i0-1]==s[j0+1])
                {
                    i0--;
                    j0++;
                }
                else    break;
            }
            if(j0-i0 > j-i) 
            {
                i = i0;
                j = j0;
            }

            i0 = k, j0 = k-1;//偶数回文
            while(i0>0 && j0<s.size()-1)
            {
                if(s[i0-1]==s[j0+1])
                {
                    i0--;
                    j0++;
                }
                else    break;
            }
            if(j0-i0 > j-i) 
            {
                i = i0;
                j = j0;
            }
        } 
        return s.substr(i,j-i+1);
    }
};
