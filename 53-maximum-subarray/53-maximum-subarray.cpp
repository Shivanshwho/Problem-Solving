class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int csum=0;
        int msum=0;
        for(int i=0;i<nums.size();i++)
        {
            csum+=nums[i];
            if(csum<0)
            {
                csum=0;
            }
            msum=max(csum,msum);
        }
        if(msum==0)
        {
            msum=INT_MIN;
        }
        for(int i=0;i<nums.size();i++ )
        {
            msum=max(msum,nums[i]);
        }
        return msum;
    }
};