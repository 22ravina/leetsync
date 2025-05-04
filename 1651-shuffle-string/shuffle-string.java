class Solution {
    public String restoreString(String s, int[] indices) {
        StringBuilder Aux = new StringBuilder(s);
        for (int i = 0; i < s.length(); i++) {
            Aux.setCharAt(indices[i], s.charAt(i));
        }
        return Aux.toString();


    }
}