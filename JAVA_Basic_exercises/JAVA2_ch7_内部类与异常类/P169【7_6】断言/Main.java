/******************************************************************************  
 *   ----------   7 - 4 断言  --------------
 *  
 * 1. 断言语句 的 语法格式
 * 
 *  使用关键字  assert  声明 一条断言语句 ，断言语句
 *  以下格式：
 *  assert booleanExpression ；
 *  asser booleanExpression： messageException;
 * 
 *  例如 ： 对于断言语句：
 *  assert number >= 0 ;的值大于 0  继续执行， 否则程序立刻执行结束
 * 
 *  在上述断言语句的语法格式中 ， booleanExpression 必须是求值 
 * 为 booleanExpression 的值 大于 true 时，并输出 messageException 表达式的值
 * 提示用户出现了 怎么样的问题
 * 
 * 
 * 2 . 启动与关闭断言语句：
 *  
 *  单使用 java 解释器直接运用应用程序，默认地关闭断言语句
 *  java  -ea  mainClass
 * 
 * 下面 例子 6 中 ，使用一个数组 存放着 5门课程的成绩，程序准备计算学生成绩的总和，
 * 在调试程序
 * 
 * 
 * assert : 断言
*******************************************************************************/

import java.util.Scanner;

public class Main{
    public static void main (String[] args) {
    int [] Score = { -120 , 98, 89 ,120, 99};
    int sum = 0;
       for(int number:Score) {
          assert number >= 0 : "负数不能是成绩";
          sum=sum+number;
       } 
        System.out.println("总成绩"  + sum);
    }

    
}

