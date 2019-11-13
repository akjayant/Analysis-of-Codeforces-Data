#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=4e5+10;
const int MOD=1e9+7;

ll ksm(ll x,ll val)
{
    ll ans=1;
    while(val)
    {
        if(val&1)(ans*=x)%=MOD;
        (x*=x)%=MOD;
        val>>=1;
    }
    return ans;
}

int main()
{
    ll n,m;
    scanf("%lld%lld",&n,&m);
    ll ans=ksm(2,m);
    ans=ksm((ans-1+MOD)%MOD,n);
    printf("%lld",ans);
    return 0;
}
