class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int,int>>vp(nums.size());
        for(int i=0;i<n;i++)
        {
            vp[i].first=nums[i];
            vp[i].second=i;
        }
            
        sort(vp.begin(),vp.end());
        int i=0,j=nums.size()-1;
        
        while(i<=j)
        {
            if(vp[i].first+vp[j].first==target)
            {
               return  {vp[i].second,vp[j].second};    
            }
            else if(vp[i].first+vp[j].first>=target)
            {
                j--;
            }
            else{
                i++;
            }
        }
        return {-1,-1};
    }
};