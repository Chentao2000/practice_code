// 成员变量有效范围 ：
// 成员在整个变量都有效 与他在类体书写先后位置无关....
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
    float bottom;           //梯形的下底（变量声明）
    void setHeight(float h) //定义一个方法 setHeight
    {
        height =  h;
    }
}

// 成员变量的编程风格 ：
// 1. 一行值只申请一个变量  // 因为不方便加上注释
// 2. 变量名字除了标识符规定外，名字首字母使用小写，从第二个单词开始使用大写（驼峰习惯）
// 3. 变量名字见名起意，避免使用 ml nl等作为变量的名字 
