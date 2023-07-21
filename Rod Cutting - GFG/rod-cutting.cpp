//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<int>max_price(n+1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j-(i+1)>=0)
                {
                    max_price[j]=max(max_price[j],max_price[j-(i+1)]+price[i]);
                }
            }
        }
        return max_price[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends