class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows==0) return ret;
        ret.push_back(vector<int>(1,1));
        for(int i=1;i<numRows;i++){
            vector<int> a(i+1);
            for(int j=0;j<=i;j++){
                if(j==0||j==i) a[j]=1;
                else a[j]=ret[i-1][j-1]+ret[i-1][j];
            }
            ret.push_back(a);
        }
        return ret;
    }
};
