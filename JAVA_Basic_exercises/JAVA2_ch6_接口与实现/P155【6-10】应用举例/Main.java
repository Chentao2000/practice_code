/******************************************************************************
进一步理解面向接口 编程 ， 我们下面这个例子 会进行举例说明 ：

设计一个广告牌， 希望所设计的广告牌可以展示许多公司的广告 ：

1 . 问题的分析 ：

    如果我们设计的创建广告牌的类中用某个具体公司的类（例如联想公式的类）声明了对象
    那么我们的广告就缺少了弹性 ，因为一旦用户需要广告牌来展示其他公司的广告词，就需要修改广告牌中的code
    
2. 设计接口:

    根据上述问题的分析 ，首先设计一个接口 Advertisement ，该接口有两个方法 
    show.Advertisement 和 getCropName（） 那么实现  Advertisement 接口的类必须要重写 
    Advertisement() 和 getGropName（）方法 即要求各个公司给出具体的广告词 和 公司名称
    
3. 设计广告牌类：

    然后我们设计Advertisement类（广告牌）该类有一个show（Advertisement abver）方法
    该方法的参数 adver 是 Advertisement 的接口类型 ，就像人们常说的  广告牌对外留有接口 
    显然 该参数 adver 可以存放任何实现 advertisement的接口对象的引用，并回调类接口的方法...

*******************************************************************************/


public class Main{
    public static void main (String[] args) {
        AdvertisementBoard board = new AdvertisementBoard();
        board.show(new BlackLandCorp());
        board.show(new WhiteCloudCorp());
    }
}











