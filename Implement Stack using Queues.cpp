class Stack {
private:
    queue<int> a,b;
public:
    // Push element x onto stack.
    void push(int x) {
        a.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(a.empty()){
        	int j=b.size()-1;
            for(int i=0;i<j;i++){
                a.push(b.front());
                b.pop();
            }
            b.pop();
        }else{
        	int j=a.size()-1;
            for(int i=0;i<j;i++){
                b.push(a.front());
                a.pop();
            }
            a.pop();
        }
    }

    // Get the top element.
    int top() {
        int ret=0;
        if(a.empty()){
        	int j=b.size()-1;
            for(int i=0;i<j;i++){
                a.push(b.front());
                b.pop();
            }
            ret=b.front();
            a.push(ret);
            b.pop();
        }else{
        	int j=a.size()-1;
            for(int i=0;i<j;i++){
                b.push(a.front());
                a.pop();
            }
            ret=a.front();
            b.push(ret);
            a.pop();
        }
        return ret;
        
    }

    // Return whether the stack is empty.
    bool empty() {
        return a.empty()&&b.empty();
    }
};
