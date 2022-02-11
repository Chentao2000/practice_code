// 例子 4-5 类与对象 P67


public calss Rect{   //矩阵
    double width;
    double height;
    double getArea(){
    
        double area = width * height;
        return area;
    }
    
    
}


public calss Lader  //梯形
{
    double above;       
    double bottom;
    double height;
    
    double getArea(){
        return (above+bottom)*height/2;
    }
    
}


public class Examp45{
    public static void main(String args[])
    {
        Rect ractangle = new Rext();
        ractangle.width = 109.87;
        ractangle.height = 25.18;
        double area = ractangle.getArea();
        System.out.println("矩阵的面积： "+ area);
        
        Lader lader = new Lader();
        lader.above = 10.798;
        lader.bottom = 156.56;
        lader.height = 18.12;
        area = lader.getArea();
        System.out.println("梯形的面积 ： "+ area);
        
    }
}
