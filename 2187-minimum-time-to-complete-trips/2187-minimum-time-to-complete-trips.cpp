class Solution {
public:
    bool helper(long long time, vector<int>& t, int req)
    {
        long long ans=0;
        for(int i=0;i<t.size();i++)
        {
            ans+=time/t[i];
        }
        return ans>=req;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        priority_queue<int, vector<int>,greater<int>>pq;
        
        long long min=1,max=1e14;
        while(min<=max)
        {
            long long mid= min+(max-min)/2;
            
            if(helper(mid,time,totalTrips))
            {
                max=mid-1;
            }
            else{
               min=mid+1; 
            }
        }
        return min;
    }
};