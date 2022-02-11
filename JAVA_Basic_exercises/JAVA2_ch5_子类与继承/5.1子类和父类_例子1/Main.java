/*****************
 * 第五章： 子类和继承
 * 子类：
 *  在类的声明中，通过使用关键字extends来定义一个类的子类
 * 
 * 类的树型结构：
 *  如果C是B的子类，B又是A的子类，习惯称C是A的子孙类
 * 
 * 子类的继承性：
 *  类有两个重要的成员：成员变量和方法
 *  子类的成员有一部分是子类自己申明、定义的，另一部分是从它的父类继承的
 *  子类中定义的实例父类的方法，就像他们在子类直接定义一样
 * 
 * 
*******************/


// 第五章例子1
public class Main {
   public static void main(String args[]) {
      Student zhang = new Student();
      zhang.age = 17;           //访问继承的成员变量
      zhang.number=100101;
      zhang.showPeopleMess();  //调用继承的方法
      zhang.tellNumber();        
      int x=9,y=29;
      System.out.print("会做加法:");
      int result=zhang.add(x,y);
      System.out.printf("%d+%d=%d\n",x,y,result);
      UniverStudent geng = new UniverStudent();
      geng.age = 21;          //访问继承的成员变量
      geng.number=6609;
      geng.showPeopleMess();  //调用继承的方法
      geng.tellNumber();        //调用继承的方法
      System.out.print("会做加法:");
      result=geng.add(x,y);      //调用继承的方法
      System.out.printf("%d+%d=%d\t",x,y,result);
      System.out.print("会做乘法:");
      result=geng.multi(x,y);
      System.out.printf("%d×%d=%d\n",x,y,result); 
   }
} 

