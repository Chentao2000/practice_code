/******************************************************************************

编写一个应用程序 ： 给出汉字 “你 ” “我” “她” 在 Unicode 位置

解题思路：将字符串 强制类型转换成 int就好了



*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
	  char  you = '你';
	  char me = '我';
	  char  she = '她';
		System.out.println("你 在 Unicode 的位置是 " + (int)you);
		System.out.println("我 在 Unicode 的位置是 " + (int)me);
		System.out.println("她 在 Unicode 的位置是 " + (int)she);
	}
}
