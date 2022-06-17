class Solution {
public:
    int f(string s)
    {
         vector<int>ch(26,0);
        for(int i=0;i<s.size();i++)
        {
            ch[s[i]-'a']++;
        }
        // int maxi=INT_MIN;
        for(int i=0;i<26;i++)
        {
            if(ch[i])return ch[i];
        }
        // return maxi;
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
       
        vector<int>ans;
        vector<int>freq;
        for(int i=0;i<words.size();i++)
        {
            int temp= f(words[i]);
            freq.push_back(temp);
        }
        sort(freq.begin(),freq.end());
        for(int i=0;i<queries.size();i++)
        {
            int temp= f(queries[i]);
            
           int it =  upper_bound(freq.begin(),freq.end(),temp)-freq.begin();
            ans.push_back(words.size()-it);
        }
        return ans;
    }
};