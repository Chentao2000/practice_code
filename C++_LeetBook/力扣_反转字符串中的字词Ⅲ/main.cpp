class Solution {
public:
    string reverseWords(string s) {
    int l =0 ,r;
    char temp;
    for(int i =0;i <s.size(); i++){
        if(s[i+1] ==' '|| i+1 == s.size()){
            r = i;
            while(r>l){
                temp = s[r];
                s[r] = s[l];
                s[l] = temp;
                r--;
                l++;
            }
            l = i+2;
        }
    }
        return s;
    }

};
