class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1=str1.size();
        int len2=str2.size();
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        for(int i =1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {   
                if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int index1=len1,index2=len2;
        string ans;
        while(index1>0&&index2>0)
        {
            if(str1[index1-1]==str2[index2-1])
            {
                ans+=str1[index1-1];
                index1--;
                index2--;
            }
            else if(dp[index1-1][index2]<dp[index1][index2-1])
            {
                ans+=str2[index2-1];
                index2--;
            }
            else{
                ans+=str1[index1-1];
                index1--;
            }
        }
        
        while(index1>0)
        {
            ans+=str1[index1-1];
            index1--;
        }
        while(index2>0)
        {
            ans+=str2[index2-1];
            index2--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};