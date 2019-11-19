#include<iostream>
using namespace std;
const long long mod=1e9+7;
const int maxn=100010;
long long fib[maxn],sum[maxn];
long long ans=2;
int main()
{
    int n,m;cin>>n>>m;
    int tip=max(n,m);
    fib[1]=1;fib[2]=1;sum[1]=1;sum[2]=2;
    for(int i=3;i<=tip;i++) fib[i]=(fib[i-1]+fib[i-2])%mod,sum[i]=(sum[i-1]+fib[i])%mod;
    (ans+=(sum[n-1]*2)%mod)%=mod;
    (ans+=(sum[m-1]*2)%mod)%=mod;
    cout<<ans<<endl;
    return 0;
}