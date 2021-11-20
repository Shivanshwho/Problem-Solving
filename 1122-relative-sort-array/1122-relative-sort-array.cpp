class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>v(1001,0);
        for(int i=0;i<arr1.size();i++)
        {
            v[arr1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<arr2.size();i++)
        {
            while(v[arr2[i]]>0)
            {
                ans.push_back(arr2[i]);
                v[arr2[i]]--;
            }
        }
        for(int i=0;i<1001;i++)
        {
            while(v[i])
            {
                ans.push_back(i);
                v[i]--;
            }
        }
        return ans;
    }
};