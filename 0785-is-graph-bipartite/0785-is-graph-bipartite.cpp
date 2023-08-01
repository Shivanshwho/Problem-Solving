class Solution {
public:
    bool is_bipartite(vector<int>&vis, vector<vector<int>>&graph,int node, int color)
    {
        vis[node]=color;
        for(auto nodes: graph[node])
        {
            if(vis[nodes]==-1)
            {
                if(!(is_bipartite(vis,graph,nodes,color^1)))
                {
                    return false;
                }
            }
            if(vis[nodes]==color)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int len=graph.size();
        vector<int>vis(len,-1);
        for(int i=0;i<len;i++)
        {
            if(vis[i]==-1)
            {
                if(!is_bipartite(vis,graph,i,1))
                {
                    return false;
                }
            }
        }
        return true;
    }
};