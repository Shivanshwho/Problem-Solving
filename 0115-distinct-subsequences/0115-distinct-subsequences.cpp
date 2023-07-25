class Solution {
public:
    int helper(string &s, string &t, int index1, int index2,vector<vector<int>>&dp)
    {
        if(index2==0)return 1;
        if(index1==0)return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        
        if(s[index1-1]==t[index2-1])
        {
            return dp[index1][index2]= helper(s,t,index1-1,index2-1,dp)+helper(s,t,index1-1,index2,dp);
        }
       return dp[index1][index2]= helper(s,t,index1-1,index2,dp);
    }
    int numDistinct(string s, string t) {
        int len1=s.length();
        int len2=t.length();
        
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
        int ans= helper(s,t,len1,len2,dp);
        return ans;
    }
};