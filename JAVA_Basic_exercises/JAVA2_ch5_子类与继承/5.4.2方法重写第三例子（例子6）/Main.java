/******************************************************************************

        子类在重写可以继承的方法时，可以完全按照自己的意图编写新的方法体
            以体现重写方法的独特行为
        重写的方法类型可以是父类方法类型的子类型
        
        下面例子 6 （方法重写 例子3）中，子类重写方法的类型是Integer类型
        （Object  类是所有类的祖先类 ）

*******************************************************************************/

class A {
    Object get(){
        return null; // 返回一个空对象
    }
}

class B extends A{
    Integer get(){
        return new Integer(100);
    }
}

public class Main{
    public static void main(String args[]){
        B b = new B();
        Integer t  = b.get();
        System.out.println(t.intValue());
    }
}















