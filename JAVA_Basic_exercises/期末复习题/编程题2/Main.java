/******************************************************************************
Java 定义接口Shape，设计矩形、圆、圆柱体等类实现Shape接口，

分别创建代表矩形、圆、圆柱体的3个对象存入一个Shape类型的数组，

并通过调用size（）方法将数组中各类图形的大小输出。
        
        
*******************************************************************************/
import java.util.Arrays;

public class Main {
 Shape[] e;
 public static void main(String[] args) {
  // TODO Auto-generated method stub
  Orthogon orthogon=new Orthogon();
  orthogon.setA(2);
  orthogon.setB(2);

Roundness roundness=new Roundness();
  roundness.setR(2);
  
  Cylinder cylinder=new Cylinder();
  cylinder.setH(2);
  cylinder.setR(2);   //K.kuimeng

    Main s1=new Main();  
  s1.e=new Shape[] {orthogon,roundness,cylinder};  
  System.out.println(Arrays.toString(s1.e));
  }}
