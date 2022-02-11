/******************************************************************************

            5.4.2 方法重写 例子5
            子类在重写computer 方法，编译无错误，子类没有覆盖computer方法
            使他的子类发生了重载，有两个方法都是computer，但两者参数不同
            
            
*******************************************************************************/

class A{
    Object get(){
        return null; //返回一个空类
    }
}


class B extends A{
    Integer get(){
        return new Integer(100);//返回一个Integer对象
    }
}

public class Main{
    public static void main (String[] args) {
        B b = new B();
        Integer t  = b.get();
        System.out.println(t.intValue());
    }
}
