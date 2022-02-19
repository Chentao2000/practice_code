/*************************************************************************
 *  JAVA 常用实用类
 *  8.1 String 类 
 *      由于在程序中经常涉及到处理和字符串有光的算法，为此JAVA专门提供了用来处理字符串序列的
 *          Sring 常 ， Sring类在 java.lang 包里 ，java.lang 包中的类被默认引入
 *  需要注意的是 ，java 把string 类 定义为 final 类 ，因此 用户不能扩展 String 类 
 * 即 String类 不可以有子类
 * 
 * 8. 1.1 构件 String 类 对象 
 * 1. 常量对象
 * - 常量池中的数据在程序运行的期间再也不允许改变 
 * 2. String 对象 
 * - 可以使用 Sting 类声明对象并且创建对象 
 *      
 *          String  s = new String (" we are student")         
 *          String t = new String("we are students")
 * 
 * String 类还有两个较常用的方法
 *  （1 ）String(char a[]) 用 字符串数组a 创建String对象 
 *  （2 ）String（char a , int startIndex , int count）提取字符数组a中的一部分字符创建对象 
 * 
 * 3. 引用 String 常量 
 * - String 常量是 对象 ，因此可以把String 常量引用赋值给一个对象 ，例如
 * 
 * String s1 ,s2
 * s1 = " 你好"
 * s2 = " 你好"
 * 
*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
	    
	    String hello = "你好";
	    String testone = "你" + "好";
	    System.out.println(hello == testone);
	    System.out.println("你好" == testone);
	    System.out.println("你好" == hello);
	    String you = "你";
	    String hi = "好";
	    String testTwo =  you + hi;
	    System.out.println(hello == testTwo);
	    String testThree = you + hi;
	    System.out.println(testThree == testTwo);
	    
	}
}
