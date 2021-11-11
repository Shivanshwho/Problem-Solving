class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();
        long long s=0,s1=0,s2=0, ans=0;
        grid[0][0]=0; grid[1][n-1]=0; // Picked by First Robot (Start & Destination)
        for(int i=0;i<n;i++)
            s+=grid[0][i]; 
        for(int i=0;i<n;i++){
            s1+=grid[0][i], s2+=grid[1][i];
            ans=max(min(s-s1,s2),ans);
        }
        return ans;
    }
};