
/****************************************************************************** 
 *          String 常用方法
 * 
 * 3. 
 *          public  boolean startsWith(String )
 *          public booleann endsWith(String s)
 * 
 *      分前缀和后缀  ： 前缀 ， 后缀
 * 
 * 4.       public int compareTo(String s) 方法           
 *      
 *      String 对象调用 compareTo(String String)方法比较大小 ，如果相同返回 0
 *  如果大于 返回 正 值， 如果小于 返回 负值
 *  
 * 
*******************************************************************************/

// 4. 例子

import java.util.*;
public class Main {
    public static void main(String args[]) {
       String [] a={"melon","apple","pear","banana"};
       String [] b={"西瓜","苹果","梨","香蕉"};
       System.out.println("使用SortString类的方法按字典序排列数组a:");
       SortString.sort(a);
       for(int i=0;i<a.length;i++) {
          System.out.print("  "+a[i]);
       }
       System.out.println("");
       System.out.println("使用类库中的Arrays类，按字典序排列数组b:"); 
       Arrays.sort(b);
       for(int i=0;i<b.length;i++) {
          System.out.print("  "+b[i]);
       }
    }
}
