class Solution {
    public int findKthPositive(int[] arr, int k) {
        // int count =0;
        // int i=0;
        // int j=1;
        // while(i < arr.length){
        //     if(arr[i]!=j){
        //         count++;
        //         if (count == k) {
        //             return j;
        //         }
        //         j++;
        //     }else{
        //         i++;
        //         j++;
        //     }
        // }
        // while (count < k) {
        //     count++;
        //     j++;
        // }
        // return j-1;
        
        int left = 0, right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left + k;

    }
}