class Solution {
public:
    int singleNumber(vector<int>& nums) {
      vector<int>pre(32,0);
      for(int i=0;i<32;i++)
      {
          for(int j=0;j<nums.size();j++)
          {
              if((1<<i)&nums[j])
              {
                  pre[i]++;
              }
          }
      }
      int num=0;
    for(int i=0;i<32;i++)
    {
        if(pre[i]%3)
        {
            num|=(1<<i);
        }
    }
       return num; 
    }
};