//// JAVA 2 实用教程 第五版  类与对象
//  面对机器语言 ： 面对过程语言 ： 面对对象语言
// 类对象 
// P53
// 类体
class Lader{
    float above;            //梯形的上底（变量声明） 
    float bottom;           //梯形的下底（变量声明）
    float height;           //梯形的高（变量声明）
    float area ;            //梯形的面积（变量声明）
        
    float computerArea()   // 定义方法computerArea 计算面积
    {
        area = (above + bottom)*height/2.0f;
        return area;
    }
    void setHeight(float h) //定义一个方法 setHeight
    {
        height =  h;
    }
}
