class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int fast = 0,slow = 0;
        int num = 0;
        while(fast < nums.size())
        {
            if(nums[fast] == 1)
            {
                num = max(fast - slow + 1,num);
            }
            else
            {
                slow = fast + 1;
            }
            fast ++ ;
        }
            return num;
    }
};
