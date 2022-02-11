// 百战 程序员 44页 双分支结构 
// 示例 4-2
import java.util.Scanner; //导包
public class Login{  // 用户登入
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入用户名");
        String userName = input.next(); //请输入用户名
        System.out.print(" 请输入密码 ");
        int pwd = input.nextInt(); // 输入密码
        // 双分支结构 if - else
        if("wangwu".equals(userName)&&pwd == 123456)
        //判断用户名 和 密码
        {
            System.out.println("登入成功 进入主界面");
        }else
        {
            System.out.println("对不起 用户名和密码不正确");
        }
    }
}
