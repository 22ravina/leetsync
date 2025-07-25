class Solution {
    public int findKthPositive(int[] arr, int k) {
        int count =0;
        int i=0;
        int j=1;
        while(i < arr.length){
            if(arr[i]!=j){
                count++;
                if (count == k) {
                    return j;
                }
                j++;
            }else{
                i++;
                j++;
            }
        }
        while (count < k) {
            count++;
            j++;
        }
        return j-1;
        
    }
}