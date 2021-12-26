
// 算法分析与在线实践 
// Algorithm foundation and online pratice

// 枚举的基本思想 ：
// 1. 建立简洁的数学模型
// 2. 减小搜索的空间
// 3. 采用合适的搜索顺序

// 列 3.2 假币问题
//  赛利有 12 枚 银币，其中有 11  枚真币，1枚假币，假币看起来和真币没有什么区别  但是重量不同 有一个天平

// 输入数据  第一行输入一个数字 n ，表示有n组测试用例
// 输出 哪一个标号是 银币还是 假币 ，并说明它 比 真币轻 ，还是比 假币重
// 输入样例  ABCD EFGH  even
//          ABCI EFJK   up
//          ABIJ  EFGH evenn
// 输出样例   K is counterfeit coin and it is light

// progarm 3.2. cpp
#include <cstdio>
int status[12];
char left[3][7], right[3][7], result[3][7];

bool Balanced() // 判断当前的情况是否满足条件
{
    int i, k, leftW, rightW;
    for (int i = 0; i < 3; i++)
    {
        leftW = rightW = 0;
        for (k = 0; k < 6 && left[i][k]; k++) // 找六次 ，看硬币在哪里
        {
            leftW += status[left[i][k] - 'A'];
            rightW += status[right[i][k] - 'A'];
        }
        if (leftW > rightW && result[i][0] != 'u') //条件 1
            return false;
        if (leftW == rightW && result[i][0] != 'e') // 条件2
            return false;
        if (leftW < rightW && result[i][0] != 'd') // 条件3
            return false;
    }
    return true;
}

int main()
{
    int i, num;
    scanf("%d", &num);
    while (num-- > 0)
    {
        for (i = 0; i < 3; i++)
            scanf("%s %s %s ", left[i], right[i], result[i]);
        for (i = 0; i < 3; i++)
            status[i] = 0;
        for (i = 0; i < 12; i++)
        {
            status[i] = 1;
            if (Balanced())
                break;
            status[i] = -1;
            if (Balanced())
                break;
            status[i] = 0;
        }
        printf("&c is the counterfeit coin  and it is &s\n", i + 'A', status[i] > 0 ? "heavy" : "light");
    }
    return 0;
}
