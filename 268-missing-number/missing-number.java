class Solution {
    public int missingNumber(int[] nums) {
        int XOR1=0;
        // for(int i=0;i<=nums.length;i++){
        //     XOR1 = XOR1^i;

        // }
        int XOR2=0;
        for(int i=0;i<nums.length;i++){
            XOR2 = XOR2^nums[i];
            XOR1 = XOR1^i;

        }
        XOR1 = XOR1^nums.length;
        return XOR1^XOR2;
        
    }
}