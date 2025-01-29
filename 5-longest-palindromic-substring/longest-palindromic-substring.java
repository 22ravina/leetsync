class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        if (n == 1) return s;  // Single character is always a palindrome

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; i++) {
            // Odd-length palindrome
            int len1 = expandFromCenter(s, i, i);
            // Even-length palindrome
            int len2 = expandFromCenter(s, i, i + 1);

            int len = (len1 > len2) ? len1 : len2;

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        // Build the result string manually
        String result = "";
        for (int i = start; i < start + maxLen; i++) {
            result += s.charAt(i);
        }
        return result;
    }

    private int expandFromCenter(String s, int left, int right) {
        int n = s.length();
        while (left >= 0 && right < n && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1; // Length of palindrome

        
    }
}