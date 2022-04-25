class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> vec;
        vec.push_back(intervals[0]);
        int j =0;
        for(int i = j+1;i<n;i++){
            if(intervals[i][0]<=vec[j][1])
                vec[j][1]=max(vec[j][1],intervals[i][1]);
            else{
                vec.push_back(intervals[i]);
                j++;
            }
        }
        return vec;
    }
};
