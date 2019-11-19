#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int maxn=1e5+5;
ll quick(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=(res*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}
ll n,m,f[maxn];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int minn=min(n,m);
    int maxn=max(n,m);
    f[1]=2,f[2]=4;
    for(int i=3;i<=maxn;i++)f[i]=(f[i-1]+f[i-2])%mod;
    ll sum=f[maxn];
    if(minn==1)cout<<sum<<endl;
    else if(minn==2)cout<<(sum+2)%mod<<endl;
    else
    {
        sum=(sum+2)%mod;
        for(int i=1;i<=minn-2;i++)sum=(sum+f[i])%mod;
        cout<<sum<<endl;
    }
    return 0;
}
