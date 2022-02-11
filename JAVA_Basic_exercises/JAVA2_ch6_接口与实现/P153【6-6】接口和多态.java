/******************************************************************************
6 -6  接口和多态:
6- 5 节学习接口回调 ，即把接口的类的实例的引用赋值给接口变量后 ，该接口变量就可以
回调类重写的接口方法。 由接口产生的多态 ，就是指不同的类在实现同一个接口时可能具有
不同的实现形式，那么接口变量在回调接口方法就可能具有多种形态

    列如 对于两个正数 A  和 B ，有的人使用算术平均公式 ： (a + b )/2 计算 算术平均值 
    而有的人使用 几何平均公式 ：根号（A x B） 计算 几何 平均值 
    
    在下面例子 4 中 ，A类和 B类都实现了 ComputerAverage 接口 ，但实现的方式不同 ，程序运行效果 如下
 
*******************************************************************************/
interface ComputerAverage{
    public double average(double a , double b);
}


class A implements ComputerAverage {
    public double average (double a ,double b){
        double aver =  0; 
        aver = (a + b )/2;
        return aver;
    }
}


class  B implements ComputerAverage{
    public double average(double a,double b){
        double aver = 0;
        aver = Math.sqrt(a * b);
        return aver;
    }
}

public class Main{
    public static void main (String[] args) {
        ComputerAverage computer;
        
        double a = 12.34 , b = 56.78;
        
        computer = new A();
        double result = computer.average(a,b);
        System.out.printf("%5.2f 和 %5.2f 的算术平均值是 : %5.2f \n", a,b,result);

        computer = new B();
         result = computer.average(a,b);
        System.out.printf("%5.2f 和 %5.2f 的算术平均值是 : %5.2f \n", a,b,result);
    }
}


