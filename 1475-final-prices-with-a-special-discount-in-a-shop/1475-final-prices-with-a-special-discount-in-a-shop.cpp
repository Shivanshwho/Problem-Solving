class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int>fprices(n);
        stack<int>stk;
        stk.push(0);
        for(int i=n-1;i>=0;i--)
        {
            while(stk.top()>prices[i])
            {
                stk.pop();
            }
            fprices[i]=prices[i]-stk.top();
            stk.push(prices[i]);
        }
        return fprices;
    }
};