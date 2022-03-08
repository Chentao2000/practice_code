

public class Cft extends Jvxing
{
    //定义新的成员变量高
    private double height;

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }
    
    //定义新的成员方法求体积
    
    public double tiji()
    {
        return this.getChang()*this.getHeight()*this.getWidth();
    }
}

