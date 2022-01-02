class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>mp;
        int n= time.size();
        mp[time[0]%60]++;
        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(mp.find(((60-(time[i]%60))%60))!=mp.end())
            {
                ans+=mp[((60-(time[i]%60))%60)];
            }
            mp[time[i]%60]++;
        }
        return ans;
    }
};