class MinStack {
    Stack<Pair> st = new Stack<>();
    public MinStack() {
        
    }
    
    public void push(int val) {
        if(st.empty()){
            st.push(new Pair(val, val)); 
        }else{
            st.push(new Pair(val,min(val,st.peek().second)));
        }
        
    }
    
    public void pop() {
        if (!st.isEmpty()) {
            st.pop();
        }

        
    }
    
    public int top() {
        return st.peek().first;
        
    }
    
    public int getMin() {
        return st.peek().second;
        
    }
    public int min(int v1,int v2){
        if(v1<v2){
            return v1;
        }
        return v2;
    }
}
class Pair {
    int first, second;
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */