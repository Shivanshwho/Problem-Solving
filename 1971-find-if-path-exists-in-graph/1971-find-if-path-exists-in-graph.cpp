class Solution {
public:
    class DSU{
       public: vector<int>parent;
        vector<int>rank;
        DSU(int m)
        {
            for(int i=0;i<m;i++)
            {
                parent.push_back(i);
                rank.push_back(1);
            }
        }
        int findPar(int child)
        {
            if(child!=parent[child])
            {
                return parent[child]=findPar(parent[child]);
            }
            return child;
        }
        void unionize(int V1, int V2)
        {
            int par1 = findPar(V1);
            int par2 = findPar(V2);
            if(par1==par2)return;
            if(rank[par1]>rank[par2])
            {
                parent[par2]=par1;
                rank[par1]+=rank[par2];
            }
            else{
                parent[par1]=par2;
                rank[par2]+=rank[par1];
            }
        }
    };
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU newSet = DSU(n);
        for(int i=0;i<edges.size();i++)
        {
            newSet.unionize(edges[i][0],edges[i][1]);
        }
        return newSet.findPar(source) == newSet.findPar(destination);
    }
};