/******************************************************************************

     与接口有关的匿名类 
     假设 Computable 是一个接口 ， 那么java允许直接用接口名和一个类体创建一个匿名的对下
     此类体被认为是实现了 Computer 接口的类去掉类申明之后哦的类体 称作为匿名类 
     下列代码就是用实现 Computertable 接口的类（匿名类）创建对象

*******************************************************************************/

interface SpeakHello{
    void speak();
}

class HelloMachine{
    public void turnOn(SpeakHello hello){
        hello.speak();
    }
}

public class Main{
    public static void main(String agrs[]){
        HelloMachine machine = new HelloMachine();
        machine.turnOn(new SpeakHello(){
            public void speak(){
                System.out.println("hello  you are welcome !");
            }
        }
            );
        machine.turnOn(new SpeakHello(){
            // 和接口SpeakHello 与接口有关的匿名类
            public void speak(){
                System.out.println("欢迎光临！");
            }
        }
        );
    }
}
