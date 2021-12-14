/******************************************************************************
- 子类和父类不在同一包的继承性

子类和父类不再同一包时，弗雷的private和友好访问权限的成员变量不会被子类继承
也就是说 ： 子类只会继承父类protec 和 publi 访问权限的成员变量作为子类的成员变量
同样的 ： 子类自会继承父类protected 和 public 访问权限 作为子类的方法

---------------------------------------------------------------------------------
5.3 继承关系UML 图
---------------------------------------------------------------------------------
5.2.4 protected 进一步说明

一个类A中的protected 成员变脸和方法可以被它的子孙类继承
1）对于子类D自己申明的变量protectd 成员变量和方法 只要other 类和 D  类
在同一个包 ，object 对象就可以访问这些protect 成员变量和方法

2） 对于子类D从父类继承的protected成员变量和方法，需要追溯到protected成员变量
或方法所在的祖先类，列如可能是A类，只要other类和A类在同一个包，object对象能访问继承protected变量和protected方法

*******************************************************************************/

class People{
    private int averHeigtht = 166;
    public int getAverHeight(){
        return averHeigtht;
    }
}
class ChinaPeople extends People{
    int height;
    public void setHeight(int h){
        // heitht = h + averHeigtht;
        height = h;
    }
    public int getHeight(){
        return height;
    }
}

public class Main{
    public static void main (String[] args) {
        ChinaPeople zhangSan = new ChinaPeople();
        
        System.out.println("子类对象未继承的averageHeight 的值是：" + zhangSan.getAverHeight());
        zhangSan.setHeight(178);
        System.out.println("子类对象的实例变量height的值是:" + zhangSan.getHeight());
        
    }
}

