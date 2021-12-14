public class ImportantUniversity extends University{
    void enterRule(double math,double english, double chinese){
        double total = math + english + chinese;
        if(total >220)
            System.out.println(total + "分数达到重点大学录取线");
        else 
            System.out.println(total + "分数未达到重点大学的录取线");
    }
}
