/******************************************************************************
一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程找出1000以内的所有完数。（java）

关键思路：
            因数不能超过 当前数字的 一半！
     
*******************************************************************************/
import java.util.*;
public class Main{
	public static void main(String[] args){
		//查找1000以内的完全数。
		List<Integer> perfectList=new ArrayList<Integer>();//记录已经检查完毕的完数。
		
		for(int i=1;i<=1000;i++){
			//1对当前数先找到所有不包含自身的因数
			List<Integer> list=new ArrayList<Integer>();//记录当前数i因数的动态数组。
			
			for(int j=1;j<i/2+1;j++){  //因为因数不可能超过当前数的一半，所以用i/2+1减少计算量，加1是为了解决当前是1的情况，比如1/2=0.5，要加一变成int 1.  18   18/2=9，不包含自身的最大的因数是9。
			
				//找出当前数i所有不包含自身的因数
				
				if(i%j==0){
					//能整除  记录当前数  用来进行完数判断
					list.add(j);
				}
			}
			//2判断当前数是否为完数
			int sumx=0;//定义当前因数和
			for(int x:list){
				sumx=sumx+x;
			}
			if(sumx==i){
				//3符合完数条件，将当前数加入到完数动态数组。
				perfectList.add(i);
			}
		}
		     //4输出所有完数。
		System.out.print("1000以内的完数有：");
		for(int w:perfectList){
				System.out.print(w+" ");
			}
		
	}
}
