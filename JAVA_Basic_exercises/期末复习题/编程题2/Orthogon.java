public class Orthogon implements Shape{
 private double a;
 private double b;
  //K.kuimeng
public double getA() {
  return a;
 }
 public void setA(double a) {
  this.a = a;
 }
 public double getB() {
  return b;
 }
 public void setB(double b) {
  this.b = b;
 }
 
 @Override
 public double size() {
  // TODO Auto-generated method stub
  //K.kuimeng
  return getA()*getB();
 }
 @Override
 public String toString() {
  return "矩形面积="+size();
 }
 }

 class Roundness implements Shape{
 private double r;

public double getR() {
  return r;
 }
 public void setR(double r) {
  this.r = r;
 }
 @Override   //K.kuimeng
 public double size() {
  // TODO Auto-generated method stub
  return 3.14*getR()*getR();
 }
 @Override
 public String toString() {
  return "圆面积="+size();
 }
 }

class Cylinder implements Shape{
  private double r;
  private double h;
  
  public double getR() {
   return r;
  }
  public void setR(double r) {
   this.r = r;
  }
  public double getH() {
   return h;
  }
  public void setH(double h) {
   this.h = h;
  }

@Override
  public double size() {
   // TODO Auto-generated method stub
   return 3.14*r*r*h;
  }
  @Override   //K.kuimeng
  public String toString() {
   return "圆柱体体积="+size();
  } }
