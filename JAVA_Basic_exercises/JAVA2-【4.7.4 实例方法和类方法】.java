// 4-7-3 实例方法和类方法的定义 ：
// 1. 实例方法和类方法的定义 
// 方法声明前 ，方法类型前面不加关键字 
// 方法声明后， static修饰的也是实例方法

//  实例方法和类方法的区别：
//  1. 对象调用实例方法 
//  2. 类名调用用类的方法 
//  3. 设计类方法的原则 

//  Example4_11.JAVA
import java.util.*;
public class Example4_11{
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int [] a = {12,24,9,23,45,90,123,19,34};
        Array.sort[](a);
        System.out.println(Arrays.toString(a));
        System.out.println("输入整数 ，程序判断整数是否在数组中");
        int number = scanner.nextInt();
        int index = Array.binarySearch(a,number);
        if(index>= 0)
            System.out.println(number + "数组 中索引为" + index + "元素值相同");
        else 
            System.out.println(number + "不与数组中任何元素值相同")
        
    }
}
