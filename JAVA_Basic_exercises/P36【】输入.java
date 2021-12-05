// 百战 JAVA 程序设计 P36 从键盘获取数据 
import java.util.Scanner;
public class Hospital2{
    public static void main (String[] args){
        // 2) 创建 Scanner对象 
        Scanner input = new Scanner(System.in); // input 是人为起的名字
        // 3) 屏幕提示信息
        System.out.print ("请输入 你的姓名 ");
        // 4) 从键盘获取 String 类型的值 赋给变量name 存储 
        String name = input.next();
        /* 重复 （3） （4） 两步 获取其他的值*/
        System.out.print("请输入就诊 序号： ");
        // 从键盘获取int类型的值赋给 变量 serialNo 存储
        int serialNo = input.nextInt();
        
        System.out.print(" 请输入 挂号费 （普通挂号费1.0 元，专家号 5 元）");
        // 从键盘获取一个字符串 将字符串索引为0 的位置上赋给变量gender 促成你
        char gender = input.next().charAt(0);
        System.out.print("请输入就诊科室： ");
        String room = input.next() ; // 从键盘获取String 类型的值赋给变量room存储
        System.out.println("\n\t ： 百战医疗挂号条（普通号）\t : 初诊");
        System.out.println("-------------------------------------------");
        System.out.println("姓名" + name + "\t 就诊序号" + serialNo  );
//        System.out.println("姓名:" + gendr + "\t\t  挂号费:" + regFee  );
        System.out.println("-------------------------------------------");
        System.out.println("科室名称 ："+ room + "\t 诊所 ：住院楼二层");
        System.out.println("-------------------------------------------");
        System.out.println("\t\t 仅当日有效");
    }
}
