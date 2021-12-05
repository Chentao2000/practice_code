// 4.9 this 关键字
// this 是 JAVA 的一个关键字 ，表示某个对象 ，
// this可以出现在 
// 实例和仿造方法中，但不可以出现在类方法中

// 4.9.1 在构造方法中使用this
public class Main{
    int leg,hand;
    String name;
    Main(String s){
        name =  s;
        this.init();
        // 可以省略this，即将“this.init() ”写成 “init()
    }
    void init(){
        leg = 2;
        hand = 2;
        System.out.println(name + "有"+ hand+"只手"+leg + "条腿");
    }
    public static void main(String args[]){
        Main boshi = new Main("布什");
         // 创建 boshi 时，构造方法中的this就是对象 boshi
         
    }
    
}
