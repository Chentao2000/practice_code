/*
- ---  8 .14
    字符串与基本数据的相互转换 
    JAVA.lang 包中的 Integer 类调用其他类方法
    如 public static int paseInt（String s）
    可以将 由 “数字” 字符组成了字符序列， 如 “876”
        转换成 int 型数据 ，列如 
        
        INT X ;
        STRING S = "876";
        X = Integer.parseInt(s);
        
        
        类似的 java.lang 包中 Byte Short .....
        
        例子 4：
*/

public class prog
{
	public static void main(String[] args) {   
       double sum = 0 , intem = 0;
       boolean computable = true;
       for(String s:args){
        try{    
                item = Double.parseDouble(s);
                sum = sum + item;
        }
        catch(NumberFormatException e){
        System.out.println(" 你输入了非法字符");
        computable = false;
        }                                                         
       }
       if(computable)
           System.out.println("sum" + sum);
		
	}
}
