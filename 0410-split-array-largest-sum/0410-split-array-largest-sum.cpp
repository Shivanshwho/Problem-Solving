class Solution {
public:
    bool is_valid(int maximum_sum, vector<int>&nums, int k)
    {
        int curr_sum=0;
        int partition_num=1;
        for(int i=0;i<nums.size();i++)
        {
            curr_sum+=nums[i];
            if(curr_sum>maximum_sum)
            {
                curr_sum=nums[i];
                partition_num++;
            }
        }
        if(partition_num>k)return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int len=nums.size();
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<len;i++)
        {
            low=max(low,nums[i]);
            high+=nums[i];
        }
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            
            if(is_valid(mid,nums,k))
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};