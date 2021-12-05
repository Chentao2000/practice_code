// 4.10 包

// 包是 JAVA 语言有效管理类的一个机制，不同的JAVA源文件，可能出现名字相同的类
// 如果区分类，就需要使用包名，包名目的是有效地区分名字相同的类
// 不同的JAVA源文件两个类名字相同的话，可以通过隶属不同的包相互区分


// 4.10.1 包语句

/*
    package 包名
    package sunrise ；
    package sun.com.cn;
*/

// 4.10.2 有包名的存储目录

// 如果一个类有包名，那么就不能在任何位置存放他，否则虚拟机无法加载这样的类
// 程序如果使用了 包语句 ，类如 
// package tom jiafei;

// 那么存储文件的目录结构必须包含如下的结构 ...\tom\jiafei

//4.10.3 运行有包名的主类
// 运行时 ，必须写主类的类名，因为使用了包名，主类的全名是 包名.主类

package tom.jiafei;
public class Main{
    public static void main(String args[]){
        Student stu = new Student(10201);
        stu.speak();
        System.out.println("主类的包名也是tom.jiafei");
        
    }
}



















