class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> mins,data;
    
    MinStack() {
    }
    
    void push(int x) {
        data.push(x);
        if(mins.empty()){
            mins.push(x);
        }else{
            if(x <= mins.top()){
                mins.push(x);
            }
        }
    }
    
    void pop() {
        int x = data.top();
        data.pop();
        
        if(!mins.empty() && x == mins.top()){
            mins.pop();
        }
        
    }
    
    int top() {
        return data.top();
    }
    
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
