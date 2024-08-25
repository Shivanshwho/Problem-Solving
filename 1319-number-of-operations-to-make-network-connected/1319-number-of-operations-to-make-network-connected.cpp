class Solution {
public:
    class DSU{
    public:
        vector<int>parent;
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
        bool unionize(int V1, int V2)
        {
            int par1 = findPar(V1);
            int par2 = findPar(V2);
            if(par1==par2)return false;
            if(rank[par1]>rank[par2])
            {
                parent[par2]=par1;
                rank[par1]+=rank[par2];
            }
            else{
                parent[par1]=par2;
                rank[par2]+=rank[par1];
            }
            return true;
        }
    };
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra=0;
        DSU newSet = DSU(n);
        for(int i=0;i<connections.size();i++)
        {
           if(!newSet.unionize(connections[i][0],connections[i][1]))
           {
               extra++;
           }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(newSet.parent[i]==i)
            {
                count++;
            }
        }
        if(count-1<=extra)return count-1;
        return -1;
            
    }
};