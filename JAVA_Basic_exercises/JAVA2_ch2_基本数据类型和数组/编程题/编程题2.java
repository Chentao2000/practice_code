/******************************************************************************

编写一个Java应用程序，输出全部的希腊字母

思路：
获取第一个和最后一个希腊字母的ASCLL值，然后用for循环遍历全部的希腊字母的ASCLL值，最后将其从int型转为char型，循环打印出所有的希腊字母。


*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
		char a = 'α',b = 'ω';
		int i;
		for ( i = (int)a; i < (int)b + 1; i ++ )
		    System.out.println((char)i + " ");
    
	}
}
