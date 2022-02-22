/*
- --- 5
* public boolean contains(String s)
    - String 对象调用 contains方法判断String 对象的字符序列
    是否包含参数 s的字符序列
- --- 6
 * public int indexOf(String s) 和 public int lastIndex(String  s)
   * 
*/

public class prog
{
	public static void main(String[] args) {
    String tom = "i am a good cat";
    System.out.println( tom.indexOf("a")); 
    tom.indexOf("good",2);
    tom.indexOf("a",7);
    tom.indexOf("w",2);
		
	}
}
