// 4_5_4   P69
// 引用类型参数 

//1. 学习对象 时候 ，一个类声明两个对象具有相同的引用 ，两者具有相同的变量
//2. 对于两个类型的引用型变量 ，如果具有相同的引用 ，就会用同样的实体

// 例子 4_7
// ------------
// Battery JAVA

public class Battery{
    int electricityAmount;
    Battery(int count )
    {
        electricityAmount = amount;
    }
}

// Radio java
public class Radio{
    void openRadio(Battery battery)
    {
        battery.electricityAmount = battery.electricityAmount - 10;
        // 消耗了电量
    }
}

public class example4_7{
    public static void main(String args[]){
        Battery manfu = new Battery(100); //创建电池对象
        System.out.println("南孚电池的储电量是: "+ nanfu.electricityAmount);
        Radio radio = new Radio();
        System.out.println("收音机开始使用南孚电池");
        radio.openRadio(nanfu);  // 打开收音机
        System.out.println("目前南孚电池的储电量是 :" + nanfu.electricityAmount);
    }
}


