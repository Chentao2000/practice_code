/******************************************************************************

    5.5.2 使用 super调用 父类函数的构造方法
    
    当用子类的构造方法创建一个子类的对象时，子类的构造方法总是
    先调用父类的某个构造方法，也就是说，如果子类的构造方法没有明显指明父类哪个构造方法
    子类调用父类不带参数的构造方法
    
    - 由于子类不继承父类的构造方法，子类在其构造的方法使用super 来调用父类的构造方法
    而且super 必须是 子类构造方法 的头一条语句：
        且如果在子类的构造方法中，没有明显地写出super关键字来调用父亲某个构造方法
        那么默认 有 super（）
*******************************************************************************/

class Student{
    int number ; String name;
    Student(){
        
    }
    Student(int number,String name){
        this.number = number ;
        this.name = name;
        System.out.println("我的名字是" + name + "学号是" + number);
    }
    
}

class UniverStudent extends Student{

    boolean 婚否;
    UniverStudent(int number,String name,boolean b){
        super(number,name);
        婚否 = b ;
        System.out.println("婚否" +  婚否)
    }
}

public class Main{
    public static void main (String[] args) {
        UniverStudent zhang = new UniverStudent(9901,"何晓林",false);
    }
}
    
    
    
    
    
    
}
 
