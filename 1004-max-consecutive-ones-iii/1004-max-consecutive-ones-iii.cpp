class Solution {
public:
    int longestOnes(vector<int>& nums, int n) {
        int start=0,end=0;
        int k=n;
        int ans=0;
        while(end<nums.size())
        {
            if(nums[end]==0)
            {
                k--;
            }
            while(k<0)
            {
                if(nums[start++]==0)
                {
                    k++;
                }
            }
            if(ans<(end-start+1))
            {
                ans=end-start+1;
            }
            end++;
        }
        return ans;
    }
    
};