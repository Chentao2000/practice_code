/******************************************************************************


6 - 3 接口回调

 和类一样 ，接口也是 JAVA 中一种重要的数据类型 ，用于接口声明的变量称为接口变量 
 那么接口变量中能存放怎么样的数据呢
 
 - 接口属于引用型变量 ，接口变量中可以存放实现该接口的类的实例的引用 ，即存放对象的引用 
 比如 Com 是一个接口 ，那么可以用Com 声明一个变量   
 
 Com com
ImpleCom object = new Implecom（）；


接口回调一词是借助了C语言指针回调的术语，表示一个变量的地址 在某一时刻存放在一个指针变量中 ，
那么指针变量可以间接操作调用该类实现的算法


*******************************************************************************/

interface showMessage{
    void showLogo(String s);
}

class Tv implements showMessage{
    
    public void showMessage(String s){
        System.out.println(s);
    }
}

class PC implements showMessage{
    public void showMessage(String s){
        System.out.println(s);
    }
}


public class Main
{
	public static void main(String[] args) {
	    
	    showMessage sm ; // 申明接口变量 
	    sm = new Tv(); // 接口变量中存放的对象
	    sm.showLogo("长城牌电视机");  //接口回调
	    sm = new PC();           //接口中存放对象的引用
	    sm.showLogo("联想 奔月 5008 PC 机"); // 接口回调
	    
	}
}
