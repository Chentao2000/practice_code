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
    // 定义一个键为字符串，值为整型的 Map 映射  
    var people: Map[String, Int] =Map("张三"->34,"李四"->30)  
    println(map)  
    println(people)  
  }  
}  

```
