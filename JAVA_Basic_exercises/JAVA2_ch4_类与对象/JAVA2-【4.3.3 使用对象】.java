
// 例4.3.3 使用对象
//  抽象的目的 是产生 类 ： 而类的目的是创建具有属性和行为的对象
//  对象不仅可以操作自己的变量改变状态 ，而且能调用类中方法产生一定的行为
// 使用 运算符 " . "对象可以实现对自己变量的访问 和方法的调用  


// 1.  对象操作自己的变量（体现对象的属性）

// 2.  对象调用类的方法（体现对象的行为）

// 3.  体现封装 

// JAVA2 P62  例子 4_3

class Journey_to_the_West_Task
{
        float height,weight;
        String head,ear;
        void speak(String s){
            head = "歪着头";
            System.out.println(s);
        }
    
}
Public class Example4_3{
    public static void main (String args[]){
        
        Journey_to_the_West_Task Zhu_Bajie,Sun_WuKong;  //声明对象
          
        Zhu_Bajie = new Journey_to_the_West_Task(); // 给对象分配变量
        
        Sun_Wukong  = new Journey_to_the_West_Task(); // 给对象分配变量
        

        Zhu_Bajie.height = 1.80f;                     // 对象给自己的变量赋值
        Zhu_Bajie.head = "大头" ;  
        Zhu_Bajie.ear = "大耳朵;";                  // 
        
        Sun_Wukong.height = 1.62f;                     // 对象给自己的变量赋值
        Sun_WUkong.weight = 1000f;  
        Sun_Wukong.head = "秀发飘飘;";                  // 
        
        System.out.println("猪八戒 的身高 : " + Zhu_Bajie.height);
        System.out.println("猪八戒 的 头 : " + Zhu_Bajie.head);

        System.out.println("孙悟空 的 头 : " + Zhu_Bajie.head);
        System.out.println("孙悟空 的 重量 : " + Zhu_Bajie.head);
        
        Zhu_Bajie.speak("俺老猪想娶媳妇");
        System.out.println("孙悟空 的 重量 : " + Zhu_Bajie.head);
        Sun_Wukong.speak("老孙我重1000斤，我想骗老猪背我");
        
        System.out.println("孙悟空现在的头: " +  Sun_Wukong.head);
        
    }                
    
}











