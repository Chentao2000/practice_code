class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int f = 0, l = 0;
        int n = nums.size();
        while(f < n){
            while (f < n && nums[f] == val){
                f++;
            }
            while( f < n && nums[f] != val ){
                nums[l++] = nums[f++];
            }
        }

        return l; 
    }
};
