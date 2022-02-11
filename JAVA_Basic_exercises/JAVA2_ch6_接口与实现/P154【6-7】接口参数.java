/******************************************************************************
6 -7 接口参数 

    如果准备给一个方法的参数传递一个数值 ，可能希望该方法的参数类型是double 类型 
    这样依赖就可以向参数传递 byte int long float 和 double 类型数据
    如果这个方法的参数是接口类型 ，我们就可以将该接口的类的实例的引用给该接口参数 
    那么接口参数就可以回调该类实现的接口方法，
    下面例子如图所示：
 
*******************************************************************************/
interface SpeakHello{
    void speakHello();
}


class Chinese implements SpeakHello{
    public void speakHello(){
        System.out.println("中国人习惯问候语言，你好 吃饭了吗？");
    }
}

class English implements SpeakHello{
    public void speakHello(){
        System.out.println("英国人习惯问候语 ， 你好 天气不错！");
    }
}

class KindHello{
    public void lookHello(SpeakHello hello) {  // 接口类型参数 
        hello.speakHello();
    }
}

public class Main{
    public static void main (String[] args) {
        
        KindHello kindHello = new KindHello();
        
        kindHello.lookHello(new Chinese());
        kindHello.lookHello(new English());
    }
}

