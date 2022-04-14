class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0,tail = numbers.size() - 1;
        while(head < tail)
        {
            if(numbers[head] + numbers[tail] < target)
            {
                head++;
            }
            else if(numbers[head] + numbers[tail] > target)
            {
                tail--;
            }
            else
            {
                return {head+1, tail+1};
            }
        }
        return {0,0};
    }
};
