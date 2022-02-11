/******************************************************************************
成员变量的隐藏：

编写子类的时，我们依然可以申明成员变量，一种特殊的情况是 ，所声明的成员变量的名字和从父类继承来的成员变量的名字基本相同
（声明类型可以不同 ） 在这种情况下：就会隐藏锁继承的成员变量
- 子类对象以及子类自己定义的方法操作与父类同名的成员变量指子类重新声明的成员变量
- 子类对象仍然可以调用从父类继承的方法操作被子类隐藏的成员变量，也就是说
- 子类就会隐藏锁继承来的成员变量
*******************************************************************************/
public class Main {
  public static void main(String args[]) {
     CheapGoods cheapGoods=new CheapGoods();
     //cheapGoods.weight=198.98; 是非法的，因为子类对象的weight已经是int型
     cheapGoods.newSetWeight(198);
     System.out.println("对象cheapGoods的weight的值是:"+cheapGoods.weight);
     System.out.println("cheapGoods用子类新增的优惠方法计算价格："+
                         cheapGoods.newGetPrice());
     cheapGoods.oldSetWeight(198.987); //子类对象调用继承的方法操作隐藏的double型变量weight
     System.out.println("cheapGoods使用继承的方法（无优惠）计算价格："+
                          cheapGoods.oldGetPrice());
  }  
}
