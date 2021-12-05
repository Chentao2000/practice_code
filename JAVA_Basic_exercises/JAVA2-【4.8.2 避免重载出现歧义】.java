// 4.8.2 避免重载出现歧义
// 重载方法之间保证相互参数不同，但要小心的是，重载方法在被调用的时可能出现歧义调用
// 下列Dog类中 cry方法就是容易引发歧义的重载方法（DOG 类没有语法错误）
class Main{
    static void cry(double m,int n){
        System.out.println("小狗");
    }
    static void cry(int m ,double n){
        System.out.println("small dog");
    }
}
// 对于上述Dog类 ，代码可以通过编译
 Dog.cry(10.0,10);

 Dog.cry(10,10.0);

// 对于下面代码  代码不可以通过编辑（没指明问题）
 Dog.cry(10,10);
