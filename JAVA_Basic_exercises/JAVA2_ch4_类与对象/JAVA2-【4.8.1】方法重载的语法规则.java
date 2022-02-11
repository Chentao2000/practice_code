// JAVA 存在两种多态，重载：（Overload） 和 重写（Override），重写是与继承有关的多态
// 方法重载是两种多态的一种
// 功能多太 ，可以向功能传递不同的消息，以便人对象根据相应的消息产生相应的行为
// 对象的行为通过类中方法来体现，行为的多态性就是方法的重载

// 方法重载的语法规则
// ------------------------------
// 一个类中可以有多个方法具有相同的名字，但这些方法的参数必须不同
// 两个方法的参数不同是指满足下列之一：
//  --- 参数的个数不同
//  --- 参数个数相同，参数列表中对应某个参数的类型不同

class People{
    float hello(int a,int b){
        return a+b;
    }
    float hello(long a,int b){
        return a-b;
    }
    double hello(double a,int b){
        return a*b;
    }
}
public class Example4_12{
    public static void main(String args[]){
        People tom = new People();
        System.out.println(tom.hello(10,20));
        System.out.println(tom.hello(10,20));
        System.out.println(tom.hello(10.0,20));
    }
}













