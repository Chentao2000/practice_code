/******************************************************************************
编程题6 ：输入满足 1 + 2 + 3 + .... + n < 8888 的最大正整数 n

关键思路：
          
     
*******************************************************************************/


import java.util.*;
public class Main{
	public static void main(String[] args){
	    int n = 0;
	    int num = 0;
        do{
            n ++;
            num += n;
            System.out.println(" while n = " + n);
            System.out.println("  num = " + num);
        }while(num < 8888);
        System.out.println(" 满足 1 + 2 + 3 + .... + n < 8888 的最大正整数 n " + (n-1));
    
    
	}
}
