// 4.11 import 语句
// 一个类可能需要另一个类的声明的对象作为自己的成员或方法中的局部变量
// 如果一个类想要使用的类和它不在一个包中 ，它怎么使用这样的类呢？
// 这正是import语句想要帮助完成的 

/*
JAVA 提供了大概130个包，在后续章节中我们将需要一些重要包的类 
例如： java.lang 包括所有的基本语言类 
       javax.swing 包含抽象窗口的工具集中的图形，文本，窗口GUI类，
       java.io 包含所有的输入/输出类
       java.util 包含实用类
       java.sql 包含操作数据库的类
       java.net 包含所有实现网络功能的类
       
       
如果想引用一个功能的所有类 ：可以用通配符号（*）来代替
        import java.util*

如果只是表示引入 java.util 包中的所有类
        import java.util.Date

*/
import java.util.Date;

public class Main{
    public static void main(String args[]){
        
        Date date = new Date();
        
        System.out.println("本机器运行的时间 : ");
        System.out.println(data.toString());
    }
}












