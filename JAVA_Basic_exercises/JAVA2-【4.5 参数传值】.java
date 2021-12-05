// JAVA2 - 实用教程 P68 -4.5 参数传值....
// 向参数传递的值 不可高于 该参数的 “传值” 例 int 不可以传给 double ..
// 反之亦然，参数得到的值类似生活中的 “原件” 的 “复印件” 改变原件

class Computer{
    int add(int x,int y)
    {
        return x + y;
    }
}

public class EXAMPLE4_6{
    public static void main (String args[])
    {
        Computer com = new Computer();
        int m  =  100;
        int n  =  200;
        int result = com.add(m,n);
        System.out.println(result);
        result = com.add(120+m,n*10+8);
        // 将表达式120+m 和 n*10+8 的值 “传值”给参数x ，y
        System.out.println(result);
    }
}
