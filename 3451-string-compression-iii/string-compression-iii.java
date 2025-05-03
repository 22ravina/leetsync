class Solution {
    public String compressedString(String word) {
        String s = "" ;
        int count = 1;
        for(int i=1;i<word.length();i++){
            char curr = word.charAt(i);
            char pre = word.charAt(i-1);
            if(curr == pre){
                count++;
                if (count == 10) { // Once it reaches 10, append 9 and reset
                s += "9" + pre;
                count = 1;
            }

                
            }else{
                s+= count;
                count =1;
                s+= pre;
            }

            
        }
        s+= count;
        s+= word.charAt(word.length()-1);
        
        return s;
    }
}