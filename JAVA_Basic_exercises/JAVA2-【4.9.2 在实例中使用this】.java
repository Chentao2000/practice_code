// 4.9.2 在实例方法中使用 this 
// this 是JAVA的一个关键字 ，表示某个对象 ，this可以出现在实例方法和构造方法中 
// 但不可以出现在类方法 
//在实例方法中使用this

// 例如 ： 
class A{
    int x;
    static int y;
    void f(){
        this.x = 100;
        A.y = 200;
    }
}

