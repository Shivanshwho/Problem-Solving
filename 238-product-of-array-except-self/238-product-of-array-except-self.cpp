class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left_arr(nums.size());
        vector<int>right_arr(nums.size());
        
        left_arr[0]=nums[0];
        right_arr[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++)
        {
           left_arr[i]=nums[i]*left_arr[i-1]; 
        }
        for(int i=n-2;i>=0;i--)
        {
            right_arr[i]= nums[i]*right_arr[i+1];
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans.push_back(right_arr[i+1]);
            }
           else if(i==n-1)
            {
                ans.push_back(left_arr[i-1]);
            }
            else{
                ans.push_back(right_arr[i+1]*left_arr[i-1]);
            }
        }
        return ans;
    }
};