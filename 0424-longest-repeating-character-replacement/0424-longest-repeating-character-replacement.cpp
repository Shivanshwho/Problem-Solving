class Solution {
public:
    int characterReplacement(string s, int k) {
        int len =s.length();
        int ans=1;
        for(int i=0;i<26;i++)
        {
            char curr= (i+'A');
            // cout<<curr<<endl;
            int l=0,r=0;
            int k_count=0;
            while(r<len)
            {
                if(s[r]!=curr)
                {
                    k_count++;
                }
                while(k_count>k)
                {
                    if(s[l]!=curr)
                    {
                        // l++;
                        k_count--;
                    }
                    l++;
                }
                ans=max(ans,(r-l+1));
                r++;
            }
        }
        return ans;
    }
};