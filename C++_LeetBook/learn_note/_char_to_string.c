// 用指针将字符串转换城字符
#include <stdio.h>

int main()
{
    unsigned char str[] = "hello c ,language";
    
    unsigned char *pstr = str;
    
    while((*pstr)){
        printf("%c " , (*pstr++));
    }
     

    return 0;
}
