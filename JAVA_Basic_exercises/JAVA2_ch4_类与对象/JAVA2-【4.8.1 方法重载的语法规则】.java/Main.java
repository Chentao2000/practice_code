public class Main{
    public static void main(String arg[]){
        Circle circle = new Circle();
        circle.setRadius(196.87);
        Tixing lader = new Tixing(196.87);
        Student zhang = new Student();
        System.out.println("zhang 计算圆形的面积");
        double result = zhang.computerArea(circle);
        System.out.println(result);
        System.out.println("zhang 计算梯形的面积");

        result = zhang.computerArea(lader);
        System.out.println(result);

    }
}
