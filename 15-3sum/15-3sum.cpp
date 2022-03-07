class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            int curr=nums[i];
            int j=i+1,k=n-1;
            
            while(j<k)
            {     
                if(nums[j]+nums[k]==-curr)
                {
                   ans.insert({curr,nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]+curr>0)
                {
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        vector<vector<int>>fans(ans.begin(),ans.end());
        return fans;
    }
};