// 例4.3 ：创建对象 ：
// 创建一个对象包括对象的声明和对象分配变量两个步骤
//1.  对象的声明：
// Lader Lader
//2.  为声明的变量分配变量 即创造对象 ，如果类中没有构造方法，
// 系统会调用默认的构造方法
// 默认的构造方法是无参数 的
class XiyouRenwu{
    float height ,weight;
    String head,ear;
    void speak(String s){
        System.out.println(s);
    }
}
public calss Example4_1()
{
    public static void main(String args[])
    {
        XiyouRenwu zhubajie;  // 申明对象
        zhubajie = new XiyouRenwu(); //为对象分配变量...使用new和默认构造方法
    }
}
