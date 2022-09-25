class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindex=0;
        int currindex=0;
        if(nums.size()==1)return true;
        for(int i=0;i<nums.size();i++)
        {  
            
            maxindex=max(currindex+nums[i],maxindex);
            if(maxindex>=nums.size()-1)return true;
            if(maxindex==currindex)return false;
            currindex++;
        }
        return true;
    }
};