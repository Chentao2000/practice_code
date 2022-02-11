// 4-7-1 实例变量 和 类变量的声明 
class Dog{
    folat x;      // 实例变量 
    static int y ;    // 类变量 
}
// 用static 给予修饰的称为类变量 否则则称为实例变量 


// 实例变量和类变量的 区别 ：

// 1. 不同对象的实例变量互不相同
// 2. 所有对象共享类变量 
// 3. 通过类名直接访问变量 
// - 不同对象的实例变量互不相同 所有对象共享类变量 

public class Lader {
    double 上底,高; // 实例变量 
    static double 下底;  // 变量
    void 设置上底(double a){
        上底  = a;
    }
    void 设置下底(){
        return 上底;
    }
    double 获取下底(){
        return 下底;
    }
}

// example 4_10 java
public class Example4_10{
    public static void main(String args[]){
        Lader.下底 = 100; // Lader 的字节码加载到内存 通过各种类名操作变量
        Lader.laderone = new lader();
        Lader.ladertwo = new lader();
        Lader.设置上底(28);
        Lader.设置下底(66);
        System.out.println("laderOne 的上底"+laderOne.获得上底());
        System.out.println("laderOner 的下底"+laderOne.获得下底());
        System.out.println("laderTwo 的上底"+laderTwo.获取上底());
        System.out.println("laderTwo 的下底"+laderTwo.获取下底());        
    }
}
