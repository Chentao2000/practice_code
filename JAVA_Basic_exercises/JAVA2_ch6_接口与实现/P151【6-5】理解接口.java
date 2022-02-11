/******************************************************************************


6 -5 理解接口 为什么要用接口呢

（1） 接口可以抽象出重要的行为标准，该行为标准用抽象方法来表示
 (2)  可以把实现接口的类的对象引用赋值 给接口变量 该接口变量可以调用该类实现的接口方法 
 即 体现 了接口的行为标准 给出具体行为 
 
 接口的思想在于它可以要求某些类有相同名称的方法 ，但方法的具体内容（方法体的内容可以不同）
 即要求这些类实现接口 ，以保证这些类一定有接口中所声明的方法（即所谓的方法绑定）
 接口要求一些类有相同名称方的同时 ，并不强迫这些类具有相同的父类
 
 下面例子中 ： 要求 MotorVehicles 类 （机动车 ） 的子类 Taxi 和 Bus 必须要有名称 brake 方法（刹车功能）
 但额外要求Taxi 名字 拥有 ControlAirTemperature 和 charge 的方法 （即 实现Taxi 的两个接口 ）
 要求客车类有名字为charge的方法 有收费功能.. 即要求Bus 只实现一个接口，运行效果 如图6.8 所示

*******************************************************************************/
abstract class MotorVehicles{
    abstract void brake();
}
interface MoneyFace{
    void charge();
}
interface ControlTemperature{
    void ControlAirTemperature();    
}

class Bus extends MotorVehicles implements MoneyFace{
    void brake(){
        System.out.println("公交车使用毂式刹车技术");
    }
    public void charge(){
        System.out.println("公共汽车 ： 一元一张 ，不计算公里数");
    }
}

class Taxi extends MotorVehicles implements MoneyFace,ControlTemperature{
    void brake(){
        System.out.println("出租车使用盘式刹车技术");
    }
    public void charge(){
        System.out.println("出租车安装了 Hair 空调");
    }
}

class Cinema implements MoneyFace,ControlTemperature{
    public void charge(){
        System.out.println("电影院 : 门票 ： 10元一张");
    }
    public void ControlAirTemperature(){
        System.out.println("电影院安装了中央空调");
    }
}

public class Main{
    public static void main (String[] args) {
        Bus bus101 = new Bus();
        Taxi buleTaxi = new Taxi();
        Cinema redStarCineama = new Cinema();
        MoneyFace fare;
        ControlTemperature temperature;
        
        fare = bus101 ;
        bus101.brake();
        fare.charge();
        fare = buleTaxi;
        
        temperature = buleTaxi;
        buleTaxi.brake();
        fare.charge();
        
        temperature.ControlAirTemperature();
        fare.charge();
        temperature.ControlAirTemperature();
    
    }
}

























