class Solution {
    public void moveZeroes(int[] nums) {
        // ArrayList<Integer> temp = new ArrayList<>();
        // for(int i=0;i<nums.length;i++){
        //     if(nums[i]!=0){
        //         temp.add(nums[i]);
        //     }
        // }
        // for(int i=0;i<temp.size();i++){
        //     nums[i]=temp.get(i);
        // }
        // for(int i=temp.size();i<nums.length;i++){
        //     nums[i]=0;
        // }
        int j = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j]= temp;
                j++;
            }
        }

    }
}