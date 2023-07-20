//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool check_cycle(vector<int>adj[],vector<int>&vis,int node)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==1)
            {
                return true;
            }
            if(vis[it]==0)
            {
                if(check_cycle(adj,vis,it))
                {
                    return true;
                }
            }
        }
        vis[node]=2;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // int len=adj.size();
        // int wid=adj[0].size();
        // // vector<vector<int>>vis(len,vector<int>(wid,0));
         vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            
                if(vis[i]==0)
                {
                    if(check_cycle(adj,vis,i))
                    return true;
                }
            
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends