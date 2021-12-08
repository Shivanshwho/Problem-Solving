// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    vector<int>ans;
    void calc(vector<int>&arr,int n, int index, int sum)
    {
        if(index==n)
        {
            ans.push_back(sum);
            return;
        }
        calc(arr,n,index+1,sum+arr[index]);
        calc(arr,n,index+1,sum);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        sort(arr.begin(),arr.end());
        calc(arr,N,0,0);
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends