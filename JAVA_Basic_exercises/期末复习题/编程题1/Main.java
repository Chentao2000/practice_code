
/******************************************************************************
            编写一个完整的程序，定义复数类 Complex 验证
            两个数据可生成复数，如给定 3，4 可生成 3 + 4i
            
    复数类 Complex 的属性有：
    
        RealPart : int 型 代表复数的实数部分
        ImageinPart int 型 代表复数的虚数部分
        
    复数类Complex 的方法有：
    
        Complex() : 构造函数 ：将复数的实部和虚部都置于0
        Complex（int r ，int i） ： 构造函数，形参r 为实部的初值，i为虚部的初值
        
        String ToString（）， 把当前复数对象的实部，虚部的组合成 a + bi 的字符串格式，
        其中 a 和 b 分别为实部 和虚部的数据 
        
        书写main 方法创建对象进行测试
        
        
*******************************************************************************/
import java.util.*;
public class Main {
	public static void main(String args[]) 
	{
		Scanner sc = new Scanner(System.in);
		Complex c1 = new Complex(1, 2);
		Complex c2 = new Complex(3, 4);
		System.out.println(c1.toString());
		System.out.println(c2.toString());
		System.out.println(c1.complexAdd(c2).toString());
		sc.close();
	}
}
class Complex
{
	private int realPart;
	private int imagInpart;
	public Complex()
	{
		realPart = 0;
		imagInpart = 0;
	}
	public Complex(int r, int i)
	{
		realPart = r;
		imagInpart = i;
	}
	public Complex complexAdd(Complex a)
	{
	//	Complex b = new Complex(); b =  this
		this.realPart = realPart + a.realPart;
		this.imagInpart = imagInpart + a.imagInpart;
		return this;
	}
	public String toString()
	{
		return (realPart + "+" + imagInpart + "i");
	}
}
