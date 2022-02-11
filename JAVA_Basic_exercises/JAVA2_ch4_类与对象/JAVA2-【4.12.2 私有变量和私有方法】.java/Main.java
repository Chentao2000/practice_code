// 4.12 访问权限 
// 我们知道，当用一个类创建了一个对象之后，该对象可以通过. 运算符操作自己的变量
// 使用类中的方法，当对象操作自己的变量和使用类中的方法是有一定的限制的

// 4.12.1 何谓访问权限：

// 所谓的访问权限，运算符通过调用 . 运算符
// 访问限制修饰符有 private protected public ，他们都是java的关键字
// 下面来说明 这些修饰符的作用

// 私有变量和私有方法 ： 
// 用关键字 private 修饰的成员变量称为私有变量和私有方法，列如
// 下列Tom 的weight 就是 私有成员变量
/*------------------------------------------------
class Tom{
    private float weight;  // weight是private的float 型变量
    private float f(float a,float b){
    return a + b;
    }
}
------------------------------------------------*/
// 当你在另外一个类Tom创建了一个对象后，该对象不能访问自己的私有变量
// 调用类中的私有方法：
/*------------------------------------------------
class Jerry{
    void g(){
        Tom cat = new Tom();
        cat.weight = 23f; // 非法
        float sum = cat.f(3,4); //非法
    }
}
------------------------------------------------*/

public class Main{
    public static void main(String args[]){
        Student zhang = new Student();
        Student geng = new Student();
        zhang.setAge(23);
        System.out.println("zhang 的年龄"+ zhang.getAge());
        geng.setAge(25);
        // zhang .age  = 23 或者 geng.age = 25 是非法的 ，因为zhang和geng已经不在
        // Studet类中
        System.out.println("geng 的年龄"+geng.getAge());
    }
}




