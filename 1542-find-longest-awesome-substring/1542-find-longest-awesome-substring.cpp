class Solution {
public:
    int longestAwesome(string S) {
          int l=S.length();
        map<int,int>mp;
        int n=0;
        mp[0]=-1;
        int max_len=1;
        for(int i=0;i<l;i++)
        {
            n=n^(1<<(S[i]-'0'));
            if(mp.find(n)!=mp.end())
            {
                max_len= max(max_len, i-mp[n]);
            }
            else{
                mp[n]=i;
            }
            for(int j=0;j<=9;j++)
            {
                if(mp.find(n^(1<<j))!=mp.end())
                {
                    max_len=max(max_len,i-mp[n^(1<<j)]);
                }
            }
        }
        return max_len;
    }
};