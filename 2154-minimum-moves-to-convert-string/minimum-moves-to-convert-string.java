class Solution {
    public int minimumMoves(String s) {
        int move =0;
        int i=0;
        while(i<s.length()){
            if(s.charAt(i) =='X'){
                move+=1;
                i+=3;
            }else{
                i+=1;
            }

        }
        return move;
        
    }
}