/******************************************************************************

分别用do-while和for循环计算1+1/2!+1/3!+1/4!… … 的前20项和

思路：
    和上一题类似 ，不过是除法而已

*******************************************************************************/

// for 的写法
public class Main
{
	public static void main(String[] args) {
	    double sum = 0;
	    int variable = 1;
	    for ( int i  = 1; i <= 20 ; i++ ){
	            variable = variable*i;
	            sum +=1.0/variable;
	            // 这里 一定 要 1.0 不然就会省掉 后面的小数
	            System.out.println(" i = " + i);
	            System.out.println("variable = "+ variable);
	            System.out.println("sum = " + sum);
	  	    System.out.println("1+1/2!+1/3!+1/4! .... + 1/20! = " + sum);
	    }

	}
}
