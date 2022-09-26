class Solution {
public:
    int majorityElement(vector<int>& nums) {
            int n=nums.size();
            int major=nums[0];
            int cnt=1;
            for(int i=1;i<n;i++)
            {
                if(nums[i]==major)
                {
                    cnt++;
                }
                else{
                    cnt--;
                    if(cnt<=0)
                    {
                        major=nums[i];
                        cnt=1;
                    }
                }
            }
        return major;
    }
};