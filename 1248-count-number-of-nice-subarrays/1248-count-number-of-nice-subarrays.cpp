class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int>dq;
        dq.push_front(-1);
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2)
            {
                dq.push_back(i);
            }
            if(dq.size()>k+1)
            {
                dq.pop_front();
            }
            if(dq.size()==k+1)
            {
                ans+=(dq[1]-dq[0]);
            }
        }
        return ans;
    }
};