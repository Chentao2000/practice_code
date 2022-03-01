/******************************************************************************
编写一个应用程序 ，使用for循环语句计算 8 + 88 + 888 + .... + 前10项的和

关键思路：
            数字 * 10 + 8 + 原先的数字
     
*******************************************************************************/
import java.util.*;
public class Main{
	public static void main(String[] args){
	    long number = 8;
	    long temp = 8;
	    long num = 0; 
	    for ( int i = 1 ;  i <= 10; i ++ )
	    {
	        num += number;
	        number = number*10 + 8;
	        System.out.println("temp =" + temp);
	 	    temp = number;

	        
	    }
	    System.out.println(" 8 + 88 + 888 + .... + 前10项的和 =" + num);
		
	}
}
