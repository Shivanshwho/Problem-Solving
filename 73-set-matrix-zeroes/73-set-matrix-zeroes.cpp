class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool p=false,q=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {    
                if(matrix[i][j]==0)
                {   if(i==0){q=true;}
                    if(j==0){p=true;}
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0||
                    matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
       if(matrix[0][0]==0)
       {    if(p)
           {for(int i=0;i<m;i++)
           {
               matrix[i][0]=0;
           }}
           
        if(q){for(int j=0;j<n;j++)
           {
               matrix[0][j]=0;
           }
             }
       }
        cout<<p<<" "<<q<<endl;
    }
};