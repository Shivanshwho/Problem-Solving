class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        if(k==0)
        {
            map<int,int>mp;
            for(int i=0;i<nums.size();i++)
            {
                mp[nums[i]]++;
            }
            for(auto it:mp)
            {
                if(it.second>1)
                {
                    ans++;
                }
            }
        }
        else{
            int prev=INT_MAX;
          for(int i=0;i<nums.size();i++)
          {  if(prev==nums[i])
             {
              continue;
             }
            else{
                if(binary_search(nums.begin(),nums.end(),nums[i]+k))
                {
                     ans++;
                 }
                prev=nums[i];
            }
          }  
        }
        return ans;
    }
};