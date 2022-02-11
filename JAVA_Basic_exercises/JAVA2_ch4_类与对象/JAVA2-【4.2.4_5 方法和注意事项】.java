// JAVA2- 第四章 55页 编程风格 
// 方法 ： 一个类的类体由两部分组成 ： 变量的声明和方法的定义
// 方法定义包括两部分 ： 方法头 和 方法体

// 方法头：------------------------------------
int speak()  //无参数的方法头 
{
    return 23;
}
int add(int x,int y,int z)  //有参数的方法头；
{
    return x + y + z;
}

//方法体： ------------------------------------

int getSum(int n)
{
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        sum = sum+i;
    }
    return sum;
}

// ！！！ 与类的成员变量不同 ，局部变量只在方法内有效 ，而且与其声明的位置有关
// 方法的参数在整个方法有效，方法内的局部变量从声明他的位置之后开始有效....

// 局部变量和全局变量..
// 局部变量没有默认值


// 4.2.5 需要注意的内容

// 类体由两部分组成，一部分是变量的声明，另一部分是方法的定义 ：
// 对于成员变量的操作只能放在方法当中。

// 例： 声明成员的变量放在方法中 
class A {
    int a = 12;
    float b = 12.56f;
}


// 但是不可以这样做 ：

class A {
    int a;
    float b;
    a = 12;  // 非法 ，这是赋值语句，不是对于变量的声明
    b = 12.56f;  // 非法 ，这是赋值语句，不是对于变量的声明
}

© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
