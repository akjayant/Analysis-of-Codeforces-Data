#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
LL n,m;
LL quickpow(LL a,LL b)
{
    LL re=1LL;
    while(b)
    {
        if(b&1) re=(re*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return re;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",quickpow(quickpow(2,m)-1LL,n));
    return 0;
}
