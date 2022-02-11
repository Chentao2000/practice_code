/******************************************************************************

 5-4 - 2 方法重写：
    
    子类通过重写隐藏的已继承的方法（方法重写称为方法覆盖）
    1. 重写的语法规则
        子类可以继承父类的某个方法，那么子类就有权利重写这个方法 ，所谓的方法重写
    2. 重写的目的
        子类通过方法的重写隐藏继承的方法，子类通过方法的重写可以把父类的状态和行为改变自身的状态和行为
        
        重写即可以操作继承的成员变量 调用继承的方法 ，也可以操作新子类新声明的成员变量
*******************************************************************************/

// 下面例子中 ：
// 高考入学考试课为三门，每门满分为100分，在高考招生的时，大学录取规则为录取最低分数线是180分
// 而重点大学重写录取规则为最低录取分析师是220分
// ImportantUniversity 是 University类的子类，子类重写夫类enterRule方法

public class Main
{
    public static void main(String args[]){
        double math = 62 ,english = 76.5 ,chinese = 67;
        ImportantUniversity univer = new ImportantUniversity();
        univer.enterRule(math,english,chinese);
        // 调用重写的方法
        math = 91;
        english = 82;
        chinese = 86;
        univer.enterRule(math,english,chinese);//通过重写的方法
    }
}
