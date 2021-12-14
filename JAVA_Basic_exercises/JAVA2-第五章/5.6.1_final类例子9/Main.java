/******************************************************************************

FIND 类： find 类可以修饰类、成员变量 和方法中的局部变量

-- 可以使用find 将类声明为 final类， final类不能被继承，即不能有子类

-- 如果使用final 修饰父类中的一个方法，那么这个方法不允许子类重写，也就是说，
-- 不允许子类隐藏可以继承的final方法 （老老实实继承 不做任何修改） 

-- 如果成员变量或局部变量被修饰成final ，那它就是常量，由于产量在运行期间，不允许在发生变换
   所以常量在声明时没有默认值，这就要求程序在申明变量时 必须制定关键的词
*******************************************************************************/

class A {
  final double PI=3.1415926;// PI是常量
  public double getArea(final double r) {
     return PI*r*r;
  }
  public final void speak() {
     System.out.println("您好，How's everything here ?");
  } 
}
public class Main {
   public static void main(String args[]) {
      A a=new A();
      System.out.println("面积："+a.getArea(100));
      a.speak();     
   }
}
