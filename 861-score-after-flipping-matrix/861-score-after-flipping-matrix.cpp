class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==0)
            {
                for(int j=0;j<n;j++)
                {
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
        for(int i=1;i<n;i++)
        {    int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(grid[j][i]==1)
                {
                    cnt++;
                }
            }
         if(cnt<m/2+(m%2==1))
         {
             for(int j=0;j<m;j++)
             {
                 grid[j][i]=1-grid[j][i];
             }
         }
         
        }
        
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int num=0;
            for(int j=n-1;j>=0;j--)
            {
                num+=grid[i][j]<<n-1-j;
            }
            ans+=num;
        }
        return ans;
    }
};