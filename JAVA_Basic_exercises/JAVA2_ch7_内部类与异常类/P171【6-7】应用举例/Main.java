/******************************************************************************  
 *   ----------   应用举例 -----------
 *  try{} 
 * catch {ExceptionSubClass e}{ }
 * finally
 * 
    本节通过一个例子熟悉待finnally子语句的 try-catch 语句
 * 
    其执行机制上 是 在 执行 try-catch 语句后 ，执行finally 子语句后，执行finnally
 * 子语句都会被执行。
 * 
 * 如果在 try-catch 语句后执行return 语句， 那么finnally 子语句 仍然 会被执行 
 * try-catch 语句中执行程序退出diamante ，则执行了 
 *  
*******************************************************************************/
public class Main {
   public static void main(String args[]) {
      CargoBoat ship = new CargoBoat();
      ship.setMaxContent(1000);
      int m =600;
      try{  
           ship.loading(m);
           m = 400;
           ship.loading(m);
           m = 367;
           ship.loading(m);
           m = 555;
           ship.loading(m);
      }
      catch(DangerException e) {
           System.out.println(e.warnMess()); 
           System.out.println("无法再装载重量是"+m+"吨的集装箱");       
      }
      finally {
          System.out.printf("货船将正点启航");
      }
  }
}
