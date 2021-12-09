// -----------------------  主函数  ----------------------------------------------------------

public class Main{
    public static void main(String args[]){
        
        Rational r1 = new Rational();
        r1.setNumberator(1);
        r1.SetDenomeinator(5);
        
        Rational r2 = new Rational();
        r2.setNumberator(3);
        r2.SetDenomeinator(2);
        
        Rational result = r1.add(r2);  // +
        int a = result.getDenominator();
        int b = result.getNumberator();
        System.out.println("1/5 + 3/2 =" + a + "/" + b);
        
        result = r1.sub(r2);  // - 
        a = result.getNumberator();
        b = result.getDenominator();
        System.out.println("1/5 - 3/2 =" + a + "/" + b);
        
        result = r1.muti(r2);  // *
        a = result.getNumberator();
        b = result.getDenominator();
        System.out.println("1/5 - 3/2 =" + a + "/" + b);
        
        result = r1.div(r2);  // / 
        a = result.getNumberator();
        b = result.getDenominator();
        System.out.println("1/5 - 3/2 =" + a + "/" + b);
        
        int n = 10 , k = 1;
        System.out.println(" 计算 2/1 + 3/2 + 5/3 + 8/5 + 13/8 + ..... 前 " + n +"项和.");
        
        Rational sum= new Rational();
       // sum.getNumberator(0);
        
        Rational item= new Rational();
        item.setNumberator(0);
        
        item.SetDenomeinator(1);
        
        
        while(k<=n){
            sum = sum.add(item);
            k ++;
            int fenzi = item.getNumberator();
            int fenmu = item.getDenominator();
            item.setNumberator(fenzi + fenmu);
            item.SetDenomeinator(fenzi);
        }
        
        
        a = sum.getNumberator();
        b = sum.getDenominator();
        System.out.println("用分数表示");
        System.out.println(a + "/" + b);
        double doubleResult = (a*1.0)/b;
        System.out.println("用小数表示");
        System.out.println(doubleResult);
        
    }
}


