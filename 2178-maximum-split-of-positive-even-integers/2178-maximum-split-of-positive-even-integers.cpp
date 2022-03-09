class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long>ans;
        if(finalSum%2)
        {
            return ans;
        }
        long long i=2;
        while(finalSum)
        {
           ans.push_back(i);
            finalSum-=i;
            i=i+2;
            // if(i>1LL)
            // {
            //   ans[ans.size()-1]+=finalSum;
            //     break;
            // }
            if(i>finalSum)
            {
                ans[ans.size()-1]+=finalSum;
                break;
            }
        }
        return ans;
    }
};