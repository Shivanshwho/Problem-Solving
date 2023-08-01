class Solution {
    int get_max(vector<int>&prices, int index, int can_buy, vector<vector<int>>& max_profit)
    {
        if(index==prices.size())
        {
            return 0;
        }
        if(max_profit[index][can_buy]!=-1)
        {
            return max_profit[index][can_buy];
        }
        int profit=0;
        if(can_buy)
        {
            profit = max(-prices[index]+get_max(prices,index+1,0,max_profit), get_max(prices,index+1,1,max_profit));
        }
        else{
            profit= max(prices[index]+get_max(prices,index+1,1,max_profit), get_max(prices,index+1,0,max_profit));
        }
        return max_profit[index][can_buy]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
       // vector<vector<int>>max_price(prices.size());
        int len =prices.size();
        vector<vector<int>>max_profit(len,vector<int>(2,-1));
        int ans =get_max(prices,0,1,max_profit);
        return ans;
    }
};