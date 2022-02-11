// 4.17 应用类型 
// 1. 有理数的封装

// 有理数: Rational  类
// ------------------------------------------------------------------------------------------
public class Rational{
    int numerator = 1 ; //分子
    int denominator = 1; //分母
    void setNumberator(int a){
        int c = f(Math.abs(a),denominator);//计算最大公约数
        numerator = a/c;
        denominator = denominator/c;
        if(numerator < 0 && denominator < 0){
            numerator = -numerator;
            denominator = -denominator;
    }
}
// --------------------------------------------------------------------------------------------
void SetDenomeinator(int b) {  //设置分母
    int c = f(numerator , Math.abs(b));  //计算最大公约数
    numerator = numerator/c;
    denominator = b/c ;
    if(numerator<0 && denominator < 0){
        numerator = -numerator;
        denominator = -denominator;
    }
}
// ---------------------------------------------------------------------------------------------

int getNumberator(){
    return numerator;
}
// ---------------------------------------------------------------------------------------------
int getDenominator(){
    return denominator;
}
// ---------------------------------------------------------------------------------------------
int f(int a,int b){
    if(a == 0)return 1;
    if(a<b){
                int c = a;
                a = b;
                b = c;
            }
    int r = a%b;
    while( r != 0 ){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

// --------------------------------------------------------------------------------------------
Rational add(Rational r) {  // 加法运算
        int a = r.getNumberator(); // 返回有理数r的分子
        int b = r.getDenominator(); // 返回有理数r的分母
        int newNumberator = numerator*b - denominator*a;
        int newDenominator = denominator*b;
        
        Rational result = new Rational();
        result.setNumberator(newNumberator);
        result.SetDenomeinator(newDenominator);
        return result;
}
//--------------------------------------------------------------------------------------------
Rational sub(Rational r){  //减法运算
    
        int a = r.getNumberator();
        int b = r.getDenominator();
        int newNumberator = numerator*b -denominator*a;
        int newDenominator = denominator*b;
        
        Rational result = new Rational();
        result.setNumberator(newNumberator);
        result.SetDenomeinator(newDenominator);
        return result;
    
}
//--------------------------------------------------------------------------------------------
Rational muti(Rational r){  //乘法运算
    
        int a = r.getNumberator();
        int b = r.getDenominator();
        int newNumberator = numerator*a;
        int newDenominator = denominator*b;
        
        Rational result = new Rational();
        result.setNumberator(newNumberator);
        result.SetDenomeinator(newDenominator);
        return result;
    
}
//--------------------------------------------------------------------------------------------
Rational div(Rational r){ //除法运算

        int a = r.getNumberator();
        int b = r.getDenominator();
        int newNumberator = numerator*b;
        int newDenominator = denominator*a;
        Rational result = new Rational();
        result.setNumberator(newNumberator);
        result.SetDenomeinator(newDenominator);
        return result;
}
}

//--------------------------------------------------------------------------------------------

















