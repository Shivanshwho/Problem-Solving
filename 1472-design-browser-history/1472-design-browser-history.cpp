class BrowserHistory {
public:
    stack<string>curr,forw;
    BrowserHistory(string homepage) {
        curr.push(homepage);
    }
    
    void visit(string url) {
        while(!forw.empty())
        {
            forw.pop();
        }
        curr.push(url);
    }
    
    string back(int steps) {
        // steps=std::min(steps,curr.size());
        if(steps>curr.size()-1)
        {
            steps=curr.size()-1;
        }
        while(steps--)
        {
            forw.push(curr.top());
            curr.pop();
        }
       return curr.top();
    }
    
    string forward(int steps) {
        // steps=min(steps,forw.size());
         if(steps>forw.size())
        {
            steps=forw.size();
        }
        while(steps--)
        {
            curr.push(forw.top());
            forw.pop();
        }
        return curr.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */