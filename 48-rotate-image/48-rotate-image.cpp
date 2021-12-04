class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n= arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
        int i=0,j=n-1;
        while(i<j)
        {
            for(int k=0;k<n;k++)
            {
                swap(arr[k][i],arr[k][j]);
            }
            i++;
            j--;
        }
    }
};