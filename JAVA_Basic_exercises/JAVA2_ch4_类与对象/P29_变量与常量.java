// 百战 JAVA程序设计教程 第29 页
public class TicketSearch{
    public static void main(String[] args) // 主方法
    {
        // 申明变量并赋值
        String ticketNo = "G393" ;  // 声明变量 ticketNo 存储车次
        String fromStation = "北京南" ; //声明变量 from Station 存储出发站
        String toStation = "长春西" ;  // 声明变量 start Time 存储到达时间 
        String startTime = "15:05" ;    // 声明变量 startTime 存储出发时间 
        String endTime = "21:04" ;    // 声明变量 endTime 存储到达时间 
        String longTime = "05:59 当日到达";    // 声明变量 ticketCont 存储历时时长
        int ticketCount = 1 ;                 // 声明变量ticketCount 存储余票张数
        double price = 433.0 ;             // 声明变量price 存储票价
        
        System.out.println("百战铁路售票系统 -->>>  余票查询");
        System.out.println("---------------------------------");
        System.out.println("车次 \t 出发站 \t 到达站 \t 出发时间\t 到达时间 \t 历时时长 \t 余票数 \t 票价 ");
        System.out.println(ticketNo + "\t" + fromStation + "\t" + toStation + "\t" + startTime + 
        "\t" + endTime +"\t" + longTime + "\t" + ticketCount + "\t" + price );
        System.out.println("---------------------------------");
    }
}
