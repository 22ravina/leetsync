class Solution {
    public int subarraySum(int[] nums, int k) {
        int appear =0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum = sum+nums[j];
                // for(int x=i;x<=j;x++){
                //     sum = sum+nums[x];
                // }
                if(sum==k){
                    appear++;

                }
            }
        }
        return appear;
    }
}