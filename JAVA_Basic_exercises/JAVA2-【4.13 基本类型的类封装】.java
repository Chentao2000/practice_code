/***************************************************************************
4.13 基本类型的类封装
JAVA的基本数据类型包括boolean byte short char int long float 和 double
java同时也提供了基本数据类型相关的类，实现对基本数据类型的封装，这里类在java.long中
分别是 byte interger short long float double Character
**************************************************************************/


/****************************************************************************
4.13.1  double 类和 float 类和

    double 类和 float 类实现了对double 和 float 的基本数据的类封装
    double 类的构造方法 double 创建一个double类型对象，
    使用float 类的构造方法float（num）创建一个float类型的对象
    
    double 对象调用doubleValue方法可以返回该对象含有的 double型数据 
    Float对象调用floatValue（）方法可以返回该对象含有的float型数据
    
****************************************************************************/



/****************************************************************************
4.13.2  byte interger short long 
        Byte(byte num)          byteValue()
        Interger(interger num)  intergerValue()
        Short(short num)        shortValue()
        Long (long num)         longValue()
****************************************************************************/


/****************************************************************************
4.13.2  Character(char c)     charValue();
****************************************************************************/

//下面例子 20 说明：将一个字符数组的小写字母变成大写字母，并将其中大写字母变成小写字母
import java.lang.*;
public class Main{
    public static void main(String args[]){
        char a[] = {'a','b','c','D','E','F'};
        for(int i = 0 ;i < a.length; i++ ){
            if(Character.isLowCase(a[i]))
                a[i] = Character.toUpperCase(a[i]);
            else if(Character.isUpperCase(a[i]))
                a[i] = Character.toLowerCase(a[i]);
        }
        for (int i = 0;i < a.length;i++)
            System.out.print(" " + a[i] );
    }
}





















