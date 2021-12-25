class Solution {
public:
    vector<vector<int>>anse;
    vector<int>temp;
    void ans(vector<vector<int>>& graph, int node,int targ)
    {
        temp.push_back(node);
        if(node==targ)
        {
            anse.push_back(temp);
            
        }
       for(auto it: graph[node])
             {
                 ans(graph,it,targ);
                     
              }
       temp.pop_back();   
       
       
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>g(n);
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                g[i].push_back(graph[i][j]);
            }
        }
       
        ans(g,0,n-1);
        return anse;
    }
};