/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ans = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;
    int k=0;
    for(int i=0;i<nums1Size;i++){
        //int found = 0;
        ans[i] = -1;
        for(int j=0;j<nums2Size;j++){
            if(nums1[i]==nums2[j]){
                //int found =0;
                for(int x = j + 1; x < nums2Size; x++){
                    if(nums2[x] > nums1[i]){
                        ans[i] = nums2[x];
                        //found = 1;
                        break;
                    }
                }

                break;
                
            }
        }
    }
    return ans;

    
}