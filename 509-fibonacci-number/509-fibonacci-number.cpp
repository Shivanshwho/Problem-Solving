class Solution {
public:
    int fib(int n) {
        int prev=1;
        int prev1=0;
        if(n<=1)return n;
        int curr;
        for(int i=2;i<=n;i++)
        {
            curr=prev+prev1;
            prev1=prev;
            prev=curr;
        }
        return curr;
    }
};