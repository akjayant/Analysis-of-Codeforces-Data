#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll f[1000005];
int n,m;
ll ans=0;
int main()
{
    scanf("%d%d",&n,&m);
    f[1]=1;
    f[0]=1;
    for (int i=2;i<=max(n,m);i++)
    {
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    ll ans=2*(f[n]+f[m]-1);
    ans%=mod;
    printf("%lld\n",ans);
}
