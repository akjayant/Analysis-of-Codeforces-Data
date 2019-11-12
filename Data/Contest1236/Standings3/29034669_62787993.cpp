#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll  p=1e9+7;
ll qpow(ll a,ll n)
{
    ll ret=1;
    while(n){
        if(n&1)ret=ret*a%p;
        a=a*a%p;
        n>>=1;
    }
    return ret;
}
int main()
{
    ll a,b;
    scanf("%lld%lld",&a,&b);
    ll ans=(qpow(2,b)+p-1)%p;
    ans=(qpow(ans,a));
    printf("%lld\n",ans);
}