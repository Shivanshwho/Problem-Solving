class Solution {
public:
    int helper(int index1, int index2, string &s, string &t, vector<vector<int>>&dp)
    {
        if(index1==0)
        {
            while(index2>0){
                if(t[index2-1]!='*')
                    return 0;
                index2--;
            }
            if(index2==0)
            {
                return 1;
            }
        }
        if(index2==0)return 0;
        if(dp[index1][index2]!=-1)return dp[index1][index2];
        if(s[index1-1]==t[index2-1])
        {
            return dp[index1][index2]= helper(index1-1,index2-1,s,t,dp);
        }
        else if(t[index2-1]=='?')
        {
            return dp[index1][index2]= helper(index1-1,index2-1,s,t,dp);
        }
        else if (t[index2-1]=='*')
        {
            return dp[index1][index2]= helper(index1-1,index2,s,t,dp)||helper(index1,index2-1,s,t,dp);
        }
        return dp[index1][index2]=0;
        }
    
    bool isMatch(string s, string p) {
        int len1= s.length();
        int len2= p.length();
        
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,-1));
        int ans=helper(len1,len2,s,p,dp);
        if(ans==0)return false;
        return true;
    }
};