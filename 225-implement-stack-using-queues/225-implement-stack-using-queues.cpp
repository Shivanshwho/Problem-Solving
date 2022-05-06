class MyStack {
public: vector<int>stk;
      
    MyStack() {
         
    }
    
    void push(int x) {
        stk.push_back(x);
    }
    
    int pop() {
        int n=stk.back();
        stk.pop_back();
        return n;
    }
    
    int top() {
        return stk.back();
    }
    
    bool empty() {
        return stk.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */