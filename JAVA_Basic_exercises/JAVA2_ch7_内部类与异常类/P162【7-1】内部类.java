/******************************************************************************
 7.1 内部类 
 
 我们知道 : 类可以有两种重要的成员 : 成员变量和方法 
 实际上 Java还允许类可以有一种成员 ： 内部类 
 Java 支持在一个类中定义另一个类 ，这样的类称内部类 ， 
 而包含内被类的类称为 内部类的            外嵌类

    内部类和外嵌类之间的重要关系如下：
    
    - 内部类的外嵌类的成员变量在内部类中仍然有效，内部类中的方法也可以调用外部类中的方法
    - 内部类的类体不可以声明类变量和类方法，外嵌类的类体中可以用内部类申明对象 ，作为外嵌类的成员
    - 内部类仅供它的外嵌类使用 ，其他类不可以用某个类的内部申明对象
    
    内部类的外嵌类的成员变量在内部类中有效，使得内部类和外嵌类交互更加方便

- 例子说明：

    某个类型的农场饲养一种特殊种类的牛 ，但不希望其他农场饲养 这种特殊中的牛
    那么这种类型的农场就可以将创建这种特殊种类的牛作为自己的内部类
    
    
*******************************************************************************/

class RedCowForm{
    static String formName;
    RedCow cow; // 内部类声明对象
    
    RedCowForm(){}
    
    RedCowForm(String s){
        cow = new RedCow(150,112,5000);
        formName = s;
    }

    public void showCowMess(){
        cow.speak();
    }

    class RedCow{   // 内部类的申明
        String cowName = " 红牛";
        int height ,weight ,price;
        RedCow(int h ,int w,int p){
            height = h;
            weight = w;
            price = p;
        }
        
        void speak(){
            System.out.println("偶是"+ cowName+ "身高： "+ height +"cm"
            + " 体重："+ weight +"kg, 生活在"+formName);
            }
        
    }
    //内部类 结束
}
//外部类结束

public class Main {
    public static void main (String args[]){
        RedCowForm form = new RedCowForm("红牛农场");
        form.showCowMess();
        form.cow.speak();
    }
}





















