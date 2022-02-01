class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int bp=100001;
        
       int profit=0;
        for(int i=0;i<prices.size();i++)
        {     
            profit= max(prices[i]-bp,profit);
            bp=min(bp,prices[i]);
        }
        return profit;
    }
};