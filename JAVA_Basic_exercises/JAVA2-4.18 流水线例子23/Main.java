/***************************************************************************************
 * 搭建流水线：
 * 如果a含有b的引用 ，b含有c的引用，abc都是对象
 * 那么就可以使用abc搭建流水线建立一个类
 * 用户只需要将要处理的数据交给流水线，流水线会依次让流水线的对象来处理数据
 * 
 * 例子24用流水线来完成分数的判定，其中Input类对象负责录入 
 * InputScore类组合了DelScore DelScrore类对象负责去掉一个最高分和一个最低分
 * DelScore组合了ComputerAver类的对象，ComputerAver类的对象负责计算平均值
 * Line类组合了InputScore DelSoren，ComputerAver三个类的实例
*************************************************************************************/
// SingGame. java

public class Main {
  public static void main(String args[]){
      Line line=new  Line();
      line.givePersonScore();
  }
}
