/******************************************************************************

异常类 ：
    
    所谓异常就是程序运行时可能出现的一些错误 ，比如试图打开一个根本不存在的文件 ...
    异常处理将会改变程序控制的流程 ，如程序有机会对错误做出处理
    这一节对异常进行初步的介绍 ，而 JAVA程序中出现异常具体异常问题在相关的描述
    
    
    异常对象 可以调用 如下方法得到或输出有关异常的信息:
    
    public String getMessage();
    public String toString();
    public void printStackTrack()
    
7-3-1 try - catch 语句
Exception
try {
    包含可能发生的异常语句
}
catch (ExceptionSubClass1 e){
    ....
}
catch (ExceptionSubClass12 e){
    ....
}
Integer ： 整数 
Parse : 分析
*******************************************************************************/

public class Main{
    public static void main (String[] args) {
        int n =0 ,m =0 , t =1000;
        try{
            m = Integer.parseInt("8888");
            n = Integer.parseInt("ab89");
            // 发生异常 转向 catch
            t = 7777; // T 没有机会被赋值了
        }
        catch(NumberFormatException e){
            System.out.println(" 发生异常: " + e.getMessage());
            
        }
        System.out.println(" n = "+ n + ",  m = " + m + ", t = " + t);
        try{
            System.out.println(" 故意抛出 I/O 异常! ");
            throw new java.io.IOException("我是故意的");
            
        //    System.out.println("这个语句肯定是没有机会执行了 必须注释掉 ！");
        }
        catch (java.io.IOException e){
            System.out.println("发生异常：  " + e.getMessage());
        }
    }
}





