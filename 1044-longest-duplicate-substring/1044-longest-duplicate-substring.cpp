class Solution {
public:
    long long p=29;
    long long mod= (1LL<<55)-1;
    long long powf(long long base, long long pow)
    {
        long long ans=1;
        while(pow)
        {
            if(pow%2==0)
            {
                base*=base;
                base%=mod;
                pow/=2;
            }
            else{
                pow--;
                ans=(ans*base)%mod;
                ans%=mod;
            }
        }
        return ans;
    }
    long long check(long long size, string &s)
    {
       long long maxp=1;
        long long i;
        set<long long>hashset;
        long long currhash=0;
        for( i=0;i<size;i++)
        {
            currhash*=p;
            currhash%=mod;
            currhash+=(s[i]-'a'+1);
            currhash%=mod;
        }
        for(int i=0;i<size-1;i++)
        {
            maxp*=p;
            maxp%=mod;
        }
        hashset.insert(currhash);
        i=1;
        while(i+size<=s.length())
        {
            currhash= ((mod+currhash-((s[i-1]-'a'+1)*maxp)%mod)%mod);
            currhash*=p;
            currhash%=mod;
            currhash+=(s[i+size-1]-'a'+1);
            currhash%=mod;
            if(hashset.find(currhash)!=hashset.end())
            {
                return i;
            }
            else{
                hashset.insert(currhash);
            }
            i++;
        }
        return 0;
    
    }
    string longestDupSubstring(string s) {
        // cout<<LL_long long_MAX<<endl;
       long long n=s.length();
        long long l=1,r=n-1;
        string  ans="";
        while(l<=r)
        {  
            long long mid=l+(r-l)/2;
            long long temp=check(mid,s);
            //cout<<mid<<" "<<temp<<endl;
            if(temp)
            {  
                ans=s.substr(temp,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        cout<<ans.size()<<" "<<s.size()<<endl;
        return ans;
    }
};