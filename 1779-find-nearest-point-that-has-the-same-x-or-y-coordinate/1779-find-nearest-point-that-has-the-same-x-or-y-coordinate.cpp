class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n=points.size();
        int ans=INT_MAX;
        int index;
        for(int i=0;i<n;i++)
        {
            if(x==points[i][0]||y==points[i][1])
            {   if(ans>abs(x-points[i][0])+abs(y-points[i][1]))
                {
                 ans= abs(x-points[i][0])+abs(y-points[i][1]);
                    index =i;
                 }
                // ans = min(ans,abs(x-points[i][0])+abs(y-points[i][1]));
            }
        }
        if(ans==INT_MAX)return -1;
        return index;
    }
};