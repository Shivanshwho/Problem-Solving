class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>>stk;
    MinStack() {
       stk.push({INT_MAX,INT_MAX}); 
    }
    
    void push(int val) {
        int temp= min(stk.top().second,val);
        stk.push({val,temp});
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
      return  stk.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */