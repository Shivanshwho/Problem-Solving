class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        vector<vector<string>>ans;
        vector<string>temp;
        
        for(int i=0;i<strs.size();i++)
        {
            string t=strs[i];
            sort(t.begin(),t.end());
            
            mp[t].push_back(strs[i]);
        }
        
        for(auto it :mp)
        {
            temp=it.second;
            ans.push_back(temp);
            
        }
        return ans;
    }
};