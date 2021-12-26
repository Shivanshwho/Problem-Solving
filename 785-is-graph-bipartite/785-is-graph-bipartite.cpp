class Solution {
public:
    bool chkbip(vector<int>&color, vector<vector<int>>&graph,int col, int node)
    {
        color[node]=col;
        
        for(auto it : graph[node])
        {   
            if(color[node]==color[it])
            {
                return false;
            }
            if(color[it]==-1)
            {
                if(!chkbip(color,graph,1-col,it))
                {
                    return false;
                }
            }
          
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
           
                if(color[i]==-1)
                {
                    if(!chkbip(color,graph,1,i))
                    {
                        return false;
                    }
                }
            
        }
        return true;
    }
};