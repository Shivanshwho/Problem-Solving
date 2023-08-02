class Solution {
public:
    int calculate_profit(vector<int>& prices,vector<vector<vector<int>>>&max_profit, int k, int index, int buy_state)
    {
        if(index==prices.size())return 0;
        if(k<0)return 0;
        if(max_profit[index][k][buy_state]!=-1)return max_profit[index][k][buy_state];
        int profit=0;
        if(buy_state)
        {
            profit = max(-prices[index]+calculate_profit(prices,max_profit,k,index+1,0),calculate_profit(prices,max_profit,k,index+1,1));
        }
        else{
            profit = max(prices[index]+calculate_profit(prices,max_profit,k-1,index+1,1),calculate_profit(prices,max_profit,k,index+1,0));
        }
        return max_profit[index][k][buy_state]= profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        vector<vector<vector<int>>>max_profit(len,vector<vector<int>>(k,vector<int>(2,-1)));
        int ans = calculate_profit(prices,max_profit,k-1,0,1);
        return ans;
    }
};