class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
           nums[abs(nums[i])]*=-1;
           if(nums[abs(nums[i])]>0)
           {
               return abs(nums[i]);
           }
        }
        return 0;
    }
};