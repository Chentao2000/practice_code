/******************************************************************************

    5.5.1 Super 关键字
    子类一旦隐藏了继承的成员变量：那么子类创建的对象不再拥有该变量
    该变量 归 关键字 Super 所有
    同样，子类一旦隐藏了继承的方法，那么子类创建的对象就不能调用被隐藏的方法
    该方法的调用由关键字super 负责，因此，如果在子类中，想使用该被子类隐藏成员变量
    就需要使用关键字 super 例子super.x, super.play() 就是访问和调用该子类隐藏变量x的方法play（）

    下面例子中，子类用super访问和调用子类隐藏的成员变量和方法
*******************************************************************************/

class Sum{
    int n ;
    float f(){
        float sum = 0;
        for (int i = 1;i <= n ;i++ )
            sum = sum + i;
        return sum;
    }
}

class Average extends Sum{
    
    int n ;
    float f(){
        float c;
        super.n = n;
        c = super.f();
        return c/n;
    }
    
    float g(){
        float c;
        c = super.f();
        return c/2;
    }
}

public class Main{
    public static void main (String[] args) {
        Average aver = new Average();
        aver.n       =  100;

        float resultOne = aver.f();
        float resultTwo = aver.g();
        System.out.println("resultOne =  "+resultOne);
        System.out.println("resultTwo =  "+resultTwo);
    }
}









