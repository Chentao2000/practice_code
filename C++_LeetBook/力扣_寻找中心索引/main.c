int pivotIndex(int* nums, int numsSize){
    int rightSum=0, leftSum=0;
    //记算nums[i...n]的和。
    for(int i=1; i<numsSize; i++)
        rightSum+=nums[i];
    if(rightSum==0)
        return 0;

    rightSum=rightSum-nums[1];
    leftSum+=nums[0];
    //计算左边和右边和并比较。
    for(int i=1; i<numsSize-1; i++){
        if(rightSum==leftSum)
            return i;
        rightSum-=nums[i+1];
        leftSum+=nums[i];
    }
    if(leftSum==0)
        return numsSize-1;
    return -1;
}

