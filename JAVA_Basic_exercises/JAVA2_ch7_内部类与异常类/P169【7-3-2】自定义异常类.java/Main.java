/******************************************************************************
 在编写程序可以扩展 Exception  类定义自己的异常类 ，然后根据程序需要来规定
 这些方法产生的异常，一个方法在声明时可以使用throws 关键字声明要产生的个异常 
 并在该方法的方法体总具体给出产生异常的操作 ，即相应的异常类创建对象 ，并使用
 throw 关键字 抛出该异常对象，导致该方法结束执行 
    
    程序 必须在 try-catch 块语句中调用可能发生异常的方法
    其中 catch 的作用就是捕获throw 关键字抛出的异常对象
    
    // throw 是 java的关键字 ，该关键字 就是抛出 异常 throw /throws是不同的关键字
    
    通常情况下 ，计算两个整数之和的方法应当有任何异常发生 ，但是 ，对某些特征的程序 
    可能不允许同号的整数做求和运算，比如当一个整数代表收入 一个整数 代表支出 
    那整数不能同号 ，下面例子 中 bank类 
    必须要向 in 输入正整数 向out 传递负数 ，并且in+out = 0 否则该方法就要抛出异常 
    因此 bank类 在声明income（int in，int out）方法
    使用关键字申明要产生的异常


*******************************************************************************/



public class Main{
    public static void main (String[] args) {
        Bank bank = new Bank();
        try {
            bank.income(200,-100);
            bank.income(300,-100);
            bank.income(400, -100);
            System.out.printf("银行目前有 %d 元", bank.getMoney());
            bank.income(200,100);
            bank.income(99999,-1000);
        }
        catch (BankException e){
            System.out.println("计算收益的过程出现如下问题");
            System.out.println(e.warnMess());
        }
            System.out.printf("银行目前有 %d 元",bank.getMoney());
        }
    }






