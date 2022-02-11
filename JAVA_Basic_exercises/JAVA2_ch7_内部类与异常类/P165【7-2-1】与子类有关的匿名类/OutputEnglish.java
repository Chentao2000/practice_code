public class OutputEnglish extends OutputAlphabet{
    // 输出英文字母的子类 
    public void output(){
        for (char c = 'a'; c <= 'z' ; c++)
        System.out.printf("%3c", c);
    }
}
