class Solution {
    public boolean rotateString(String s, String goal) {
        if (s.length() != goal.length()) return false;

        StringBuilder sb = new StringBuilder(s);
        for(int k=0;k<s.length();k++){
        char first = sb.charAt(0);
        for(int i=1;i<s.length();i++){
            sb.setCharAt(i-1,sb.charAt(i));
        }
        sb.setCharAt(s.length()-1,first);
        if (sb.toString().equals(goal)) {
                return true;
            }

        }
        return false;
    }
}