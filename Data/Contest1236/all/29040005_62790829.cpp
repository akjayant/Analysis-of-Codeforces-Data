#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(a,b) memset(a,b,sizeof(a))
const ll mod=1e9+7;
ll mi(ll a,ll b)
{
    ll ret=1LL;
    while(b)
    {
        if(b&1)ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret;
}
ll n,m;

int main()
{
    scanf("%lld%lld",&n,&m);
    ll ans=mi((mi(2LL,m)-1+mod),n)%mod;
    printf("%lld\n",ans);
    return 0;
}
