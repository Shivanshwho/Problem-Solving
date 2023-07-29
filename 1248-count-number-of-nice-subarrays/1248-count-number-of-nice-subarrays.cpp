class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0;
        int cnt=0,odd=0;
        int ans=0;
        while(r<n)
        {
            if(nums[r]%2)
            {
                cnt=0;
                odd++;
            }
            while(odd==k)
            {
                cnt++;
                if(nums[l++]%2)
                {
                    odd--;
                }
            }
            ans+=cnt;
            r++;
        }
        return ans;
        
    }
};