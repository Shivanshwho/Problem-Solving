class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        stack<int>stk;
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            while(stk.size()!=0&&temperatures[stk.top()]<=temperatures[i])
            {
                stk.pop();
            }
            if(stk.size()==0)
            {
                ans.push_back(0);
            }
            else{
                ans.push_back(stk.top()-i);
            }
            stk.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};