// 百战 程序员 43页 分支结构
// 示例 4-1 
import java.util.Scanner; //导包
public class IDdemo{
    public static void main(String[] args)
    {
        //(2) 创建Scanner 对象 
        Scanner input = new Scanner(System.in);
        //(3) 屏幕显示：
        System.out.println("明天晴天吗？（ y/ 其他字符）");
        //(4) 输入 数据
        char answer = input.next().charAt(0);
        if(answer=='y')
        {
            // 判断输入的字符是否为y
            System.out.println("可以去海边踏浪捡贝壳-_-");
            
        }
    }
}
