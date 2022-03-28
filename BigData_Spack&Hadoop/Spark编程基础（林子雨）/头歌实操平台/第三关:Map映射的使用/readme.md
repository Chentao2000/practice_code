Map 映射的使用是之前学JAVA没学到的！
好好学习！

---

Map 映射简介
Map(映射)是一种可迭代的键值对（key/value）结构，它的所有的值都可以通过键来获取，且 Map 中的键都是唯一的：

```c

object ForDemo {  
  def main(args: Array[String]): Unit = {  
    // 定义一个空 Map 映射  
    var map: Map[Nothing, Nothing] =Map()  
    // -- map 是一个关键字 定义了一个映射
    // 定义一个键为字符串，值为整型的 Map 映射  
    var people: Map[String, Int] =Map("张三"->34,"李四"->30)  
    println(map)  
    println(people)  
  }  
}  

```

Scala Map 有三个基本操作：  

![1648455775(1)](https://user-images.githubusercontent.com/68007558/160356825-d11681ab-ebc6-4ca1-a358-ed6b8c8e9890.png)

这些基本的操作可应用于任何 Map 映射。实例如下:

```c
object Test {  
   def main(args: Array[String]) {  
      val colors = Map("red" -> "#FF0000",  
                       "azure" -> "#F0FFFF",  
                       "peru" -> "#CD853F")
      val nums: Map[Int, Int] = Map()
      println( "colors 中的所有键 : " + colors.keys )  
      println( "colors 中的所有值 : " + colors.values )  
      println( "检测 colors 是否为空 : " + colors.isEmpty )  
      println( "检测 nums 是否为空 : " + nums.isEmpty )  
   }  
}  
```


## 任务要求 ：
平台将使用测试集运行你编写的程序代码，若全部的运行结果正确，则通关。

例：
测试输入：  

    hello-hello,hi,job-hi  

预期输出：  

    单词： hi, 个数 1  
    单词： hello, 个数 2
    

其实我主要是不懂怎么读入它的输入和输出 ：

读取输入：

      import scala.io.StdIn
      StdIn.readLine()



```c

    import scala.io.StdIn
    object ForDemo {  
      def main(args: Array[String]): Unit = {  
        // 请在 Begin-End 间编写代码  
        /********** Begin **********/  
        // 读取字符串  
        val line: String =StdIn.readLine()  
        // 依据逗号切割字符串，得到一个数组  
        var arr =line.split(",")  
        // 将数组中每个元素转化为（单词元素，1）  
        var map1: Seq[(String, Int)] =arr.flatMap(x=>x.split("-")).map(x=>(x,1))  
        // 按照单词对键值对分组  
        var r1: Map[String, Seq[(String, Int)]] = map1.groupBy(_._1)  
        // 统计各单词的个数  
        var count= r1.map(t => (t._1,t._2.size))  
        // 遍历输出结果  
        count.keys.foreach{ i =>  
          print( "单词： " + i +",")  
          println(" 个数 " + count(i) )}  
        /********** End **********/  
      }  
    }  

```


