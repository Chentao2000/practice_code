// 一个手机可以组合任何的SIM卡，下面的例子9 模拟手机和SIM卡的组合关系 ，涉及的类如下 ：
// SIM 类负责创建SIM卡 
// Mobile Telephone 类负责创建手机 ，手机可以组合成一个SIM卡，并可以调用 SetSIM(SIM card)方法更改SIM卡

public class SIM{
    long number ;
    SIM(long number)
    {
        this.numeber = number ;
    }
    long getNumber()
    {
        return number ;
    }
}
public class MobileTelephone{
    SIM sim;
    void setSIM(SIM card){
    sim = card;
    }
    long lookNumber(){
        return sim.getNumbe();
    }
}

public class Example4_9
{
    public static void main(String args[])
    {
        SIM simOne = new SIM(13889776509L);
        MobileTelephone mobile = new MobileTelephone();
        mobile.setSIM(simOne);
        System.out.println("手机号码",mobile.lookNumber());
        mobile.setSIM(simTwo); //更换SIM 卡
        System.out.println("手机号码",mobile.lookNumber());
    }
}
