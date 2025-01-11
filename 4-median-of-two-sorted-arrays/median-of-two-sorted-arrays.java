class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int totalcount = nums1.length + nums2.length;
        int[] merged = new int[totalcount];
        
        System.arraycopy(nums1, 0, merged, 0, nums1.length);
        System.arraycopy(nums2, 0, merged, nums1.length, nums2.length);
        
        Arrays.sort(merged);
        
        if (totalcount % 2 == 1) { 
            return merged[totalcount / 2];
        } else {
            int mid1 = totalcount / 2 - 1;
            int mid2 = totalcount / 2;
            return (merged[mid1] + merged[mid2]) / 2.0;
        }
    }
}
