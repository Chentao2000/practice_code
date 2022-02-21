/****************************************************************************** 
 *          String 常用方法
 * 
 * 1. public int length()
 *      String 类中会获取 length（） 方法来获取一个String 对象的字符序列的长度
 * 
 * 2. public boolean equals(String s)
 *      String 对象调用equal (String s) 方法比较当前字符序列是否与参数s指定string
 *      对象的字符序列相同    
 *  
 * 

*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
        //1 
        String china = "1945年抗战胜利";
        int n1 ,n2;
        n1 = china.length();
        n2 = "小鸟 fly".length();
	    
	    // 2
		String s1 ,s2;
		s1 = new  String("天道酬勤");
		s2 = new  String("天道酬勤");
		System.out.println(s1.equals(s2));
		System.out.println(s1 == s2);
		String s3 , s4;
		s3 = "we are student";
		s4 = new String("we are student");
		System.out.println(s3.equals(s4));
		System.out.println(s3 == s4);
		String s5 , s6;
		s5 = "勇者无敌";
		s6 = "勇者无敌";
		System.out.println(s5.equals(s6));
		System.out.println(s5 == s6);
		
		
	}
}
