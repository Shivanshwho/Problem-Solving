class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans^=nums[i];
        }
        int index=0;
        while(1)
        {
            if((1<<index)&ans)
            {
                break;
            }
            index++;
        }
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if((1<<index)&nums[i])
            {
                a^=nums[i];
            }
            else{
                b^=nums[i];
            }
        }
        return {a,b};
    }
};