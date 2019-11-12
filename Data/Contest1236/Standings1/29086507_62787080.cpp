#include <bits/stdc++.h>

using namespace std;
long long mod=1e9+7;
long long powr(long long a,long long b)
{
    a=a%mod;
    long long base=a;
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*base%mod;
        }
        b=b>>1;
        base=base*base%mod;
    }
    return ans;
}
int main()
{
    long long n,m;
    cin>>n>>m;
    long long sum=(powr(2,m)-1+mod)%mod;
    sum=powr(sum,n)%mod;
    cout<<sum<<endl;
    return 0;
}
