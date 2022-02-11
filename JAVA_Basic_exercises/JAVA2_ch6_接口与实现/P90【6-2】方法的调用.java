
// 百战 程序员 90页 方法的调用
// 示例 6 -2

    public calss TestCale
    {
        public static void main(String [] args)
        {
            /*使用一个return去结束一个方法，
                如果方法的执行结果为void ，return 可以省略不写
            */
            Scanner input = new Scanner(System.in);// 创建对象
            System.out.println("请输入第一个加数:");
            int a = input.nextInt();
            System.out.println("请输入第二个加数");
            int a = input.nextInt();
            
            int s = Cale.add(a,y);//方法的调用
            System.out.println("结果是："+s);
            // return 用于结束方法 ，可以省略不写
        }
    }
