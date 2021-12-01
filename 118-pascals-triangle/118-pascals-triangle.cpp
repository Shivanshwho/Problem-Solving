class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int i=1;
        vector<int>temp;
        vector<vector<int>>ans;
        while(i<=numRows)
        {   
            for(int j=1;j<=i;j++)
            {
                if(j==1||j==i)
                {
                    temp.push_back(1);
                }
                else{
                    temp.push_back(ans[i-2][j-1]+ans[i-2][j-2]);
                }
            }
            ans.push_back(temp);
            temp.clear();
            i++;
        }
        return ans;
    }
};