int missingNumber(int* nums, int numsSize) {
    int sum =0;
    int actualsum =0;
    for(int i=0;i<=numsSize;i++){
        sum+=i;
    }
    for(int i=0;i<numsSize;i++){
        actualsum+=nums[i];
    }
    return sum-actualsum;

    
}