class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxSize=0;
        int count=0;
        int end=0;
        while(end<nums.size())
        {
            if(nums[end]==0)
            {
                count=0;
            }
            else{
                count++;
            }
            maxSize=max(maxSize,count);
            end++;
        }
        return maxSize;
    }
    
};