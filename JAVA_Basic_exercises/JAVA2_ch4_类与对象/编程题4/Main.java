/******************************************************************************

用类描述计算机中CPU的速度和硬盘的容量，
要求Java应用程序有4个类，
名字分别为：pc CPU harddisk 和Test ，其中TEST是主类。

CPU类要求getSpeed（）返回speed的值，要求setSpeed（int m）方法将参数m的值赋值给speed；

HardDisk类要求getAmount()返回amount的值，要求setAmount（int m）方法将参数m的值赋值给amount;

PC类要求setCPU（CPU c）将参数c的值赋值给cpu，要求setHardDisk（HardDisk h）方法将参数h的值赋值给HD，要求show（）方法能显示cpu的速度和硬盘的容量。

主类Test的要求：

（1）main方法中创建一个CPU对象cpu，cpu将自己的speed设置为2200。

（2）main方法中创建一个HardDisk对象disk，disk将自己的amount设置为200。

（3）main方法中创建一个PC对象pc。

（4）pc调用setCPU(CPU c)方法，调用是实参是cpu。

（5）pc调用setHardDisk(HardDisk h)方法，调用是实参是disk。

（6）pc调用show（）方法。

*******************************************************************************/

public class Main {


public static void main(String[] args) {
    // TODO Auto-generated method stub
    CPU cpu = new CPU ();
    cpu.speed=100;
    HardDisk hardDisk =new HardDisk();
    hardDisk.amount=100000000;
    PC pc=new PC();
    pc.setCPU(cpu);
    pc.setHardDisk(hardDisk);
    pc.show();

}
}


