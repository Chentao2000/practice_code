// 例子 4-4 

class Point{
    int x,y;
    void setXY(int m,int n)
    {
        x = m;
        y = n;
    }
}
public class Exapmle
{
    public static void main(String args[])
    {
        Point p1,p2;
        p1 = new Point();
        p2 = new Point();
        
        System.out.println("p1的引用 ：" +p1);
        System.out.println("p1的引用 ：" +p2);
        p1.setXY(1111,2222);
        p2.setXY(-100,-200);
        
        System.out.println("p1的x，y坐标 ：" +p1.x+","+p1.y);
        System.out.println("p2的x，y坐标 ：" +p2.x+","+p2.y);
        
        p1=p2;  
        
        System.out.println("将P2 的引用赋给 P1 后");
        System.out.println("p1 的引用 "+p1);
        System.out.println("p2 的引用 "+p2);

        System.out.println("p1的x,y 坐标 ");   
        System.out.println("p1的x，y坐标 ：" +p1.x+","+p1.y);
        System.out.println("p2的x，y坐标 ：" +p2.x+","+p2.y);
        
    }
}
// 与C++ 不同 ，在JAVA语言中 ，类有构造方法 ，但没有折购方法 ，JAVA运行环境有垃圾收集装置 ，因此C++程序员那样
// 这要时刻自己检查对象应该用哪种使用方法择购方法 注释
// JAVA 运行环境中的 垃圾收集 发现堆中 的实体不再被栈中任何对象所引用
