class Solution {
    public int longestContinuousSubstring(String s) {
        int maxLength =0;
        int strLength =1;
        int n = s.length();
        for(int i=0;i<n-1;i++){
            if(s.charAt(i)+1==s.charAt(i+1)){
                strLength++;
            }else{
                maxLength = Math.max(maxLength,strLength);
                strLength=1;
            }
        }
        maxLength = Math.max(maxLength,strLength);
        return maxLength;
        
    }
}