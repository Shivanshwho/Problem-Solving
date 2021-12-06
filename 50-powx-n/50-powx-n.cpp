class Solution {
public:
    double myPow(double x, int n) {
        double ans =1;
        long long s= n;
        if(x==1)return 1;
       bool p=false;
        if(s<0)
        {
            s*=-1;
            p=true;
        }
        while(s)
        {
            if(s%2==0)
            {
                x=x*x;
                s/=2;
            }
            else{
                ans*=x;
                s--;
            }
        }
        if(p)
        {
            return 1/ans;
        }
        return ans;
    }
};