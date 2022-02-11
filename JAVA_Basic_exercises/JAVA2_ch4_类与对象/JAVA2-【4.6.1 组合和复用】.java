// 组合和复用 .... ``
// 如果一个对象a组合了对象b ，那么对象a就可以委托对象b 调用其方法，即对组合方式复用b的方法：

// 1. 通过组合对象来复用的方法也被称为黑盒复用 ，因为当前对象所包含的对象的方法的细节 是一无所知的....

// 2. 当前对象随时可以更换包含的对象，即对象与所包含的对象属于弱耦合关系 

// example 8 展示的 圆锥和圆的组合关系 ，圆锥的底是个圆 圆锥对象在计算体积的知识
// 首先委托 圆锥的底(一个Cricle对象) boottom 调用getArea方法


// Circle. java
public class Circle{
    double radius,area;
    void setRadius(double r)
    {
        radius = r;
    }
    double getRadius(){
        return radius;
    }
    double getArea(){
        area = 3.14*radius*radius;
        return area;
    }
}

// Circular . java
public calss Circular{
        Circle bottom ;
        double height;
        

    
    void setBottom(Circle c)//设置圆锥的底是一个Circle对象
    {
        bottom = c;
    }
    
    
    void setHeight(double h){
        height = h;
    }
    
    double getVolme(){
        if(bottom  == null)
        {
            return -1 ;
        }
        else 
            return bottom.getArea()*height/3.0;
    }
    double getBottomRadius(){   // Radius 半径
        return bootom.getBottomRadius();
    }
    public void setBottomRadius(double r){
        bottom.setBottomRadius(r);
    }
}

// 例子 4-8

public class example4_8 {
    public static void main(String args[])
    {
        Circle circle = new Circle();
        // 代码一
        // 内存中诞生了一个 circle 对象 （圆），并且circle对象的 radius的半径是10，内存对象模型入图4.16所示
        // circle ---> radius
        circle.setRadius(10);
        // 代码二
        // 之后内存中诞生了一个circular 对象（圆锥） 
        // 注意此时circular 对象（圆锥）的bottom成员还是一个空对象 ，内存的对象模型如图4.17所示
        //          -> 
        //          -> circle  -> radius
        // circular -> null     bottom  //注意此时bottom还是空对象       
        //          -> height   
        Circular circular = new Circular();
        // 代码三 
        System.out.println("circle 的引用 ",circle);  
        System.out.println("圆锥的 botoom 引用 :"+circular.bootom");

        circular.setHight(5);
        circular.setBottom(circle);     //代码四
        //之后 circle 对象的引用  15db9472 以传值方式传递 circular 对象 的bottom 
        // 因此 bottom 对象和circle 对象具有同样的实体 radius ，内存对象模型如图所示 
        //          circle -> radius                circle -> radius
        //          -> ↑  bottom          circular  ->↑ 
        // circular ->    height                    ->
        System.out.println("圆锥的 botoom 引用 :"+circular.bootom");
        System.out.println("圆锥的 体积 :"+circular.getVolme");
        System.out.println("修改 circle的 半径 bootom 的半径同样变化:");   
        
        circular.getRadius(50);     
        
        System.out.println("botoom的半径 :"+circular.getBottomRadius());
        System.out.println("重新创建circle，circle的引用将发生变化");
        
        circle = new Circle();//重新创建 circle 代码 六
        
        // 执行代码 六：
        // 使得circle 的引用发生变化，即重新创建对象circle 对象，使得circle对象获得了新的实体
        // 此时circle 对象的radius的值为0 但circle对象先前的实体（radius）不被释放
        // 因此该实体还被circluar （圆锥）的bottom底 所引用 ，最初circle对象的引用并不影响circluar的bottom的引用
        // bottom的对象值 仍然是 20！
        // 图形 省...
        //
        // 
        //
        System.out.println("但不影响 circular 的bottom 的引用");
        System.out.println("圆锥的bottom 的引用："+circular.bottom);        
    }
}
