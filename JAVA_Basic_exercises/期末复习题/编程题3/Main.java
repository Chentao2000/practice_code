

/******************************************************************************
按要求编写一个Java应用程序：

    （1）定义一个类，描述一个矩形，包含有长、宽两种属性，和计算面积方法。
    （2）编写一个类，继承自矩形类，同时该类描述长方体，具有长、宽、高属性
        （3）编写一个测试类，对以上两个类进行测试，创建一个长方体，定义其长、

宽、高，输出其底面积和体积。
        
*******************************************************************************/
public class Main {

    public static void main(String[] args) {

        //实例化矩形对象求面积
        Jvxing j= new Jvxing();
        j.setWidth(10);
        j.setChang(15.3);
        System.out.println("矩形的长为："+j.getChang()+"  宽为："+j.getWidth());
        System.out.println("矩形的面积为："+j.mianji());
        
        //实例化长方体对象求体积
        Cft c = new Cft();
        c.setChang(2);
        c.setHeight(3.2);
        c.setWidth(100);
        System.out.println("长方体的长为："+c.getChang()+"  宽为："+c.getWidth()+"  高为："+c.getHeight());
        System.out.println("长方体的体积为："+c.tiji());
                
    }

}
