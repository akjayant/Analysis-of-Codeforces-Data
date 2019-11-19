#include <bits/stdc++.h>
using namespace std;
int n,m;
#define ll long long
const ll mod=1e9+7;
ll f[100050];


int main()
{
    f[2]=2,f[3]=2;
    for(int i=4;i<=100000;++i)
        f[i]=f[i-1]+f[i-2],f[i]%=mod;
    cin>>n>>m;
    if(n>m)swap(n,m);
    ll sum=2;
    for(int i=2;i<=n;++i)
    {
        sum+=f[i];
        sum%=mod;
    }
    for(int i=2;i<=m;++i)
    {
        sum+=f[i];
        sum%=mod;
    }
    printf("%lld\n",sum);
    return 0;
}
