/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int n = numsSize*2;
    int *ans = malloc(n*sizeof(int));
    
    *returnSize = n;
    memcpy(ans,nums,numsSize* sizeof(int));
    memcpy(ans+numsSize,nums,numsSize* sizeof(int));

    return ans;
    
}