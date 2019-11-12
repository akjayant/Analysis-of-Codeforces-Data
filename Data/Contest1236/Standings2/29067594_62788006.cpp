#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll mul(ll a,ll b,ll mod)//快速乘
{
    a%=mod, b%=mod;
    return (a*b-(ll)((long double)a/mod*b)*mod+mod)%mod;
}
ll fast_pow(ll x,ll y,ll m)//快速幂
{
    ll ans=1;
    x%=m;
    while(y)
    {
        if(y&1) ans=mul(ans, x, m);
        y >>= 1;
        x=mul(x, x, m);
    }
    return ans;
}
int main()
{
    ll n, m;
    cin>>n>>m;
    ll sum;
    sum=fast_pow(2ll, m, mod);
    sum=(sum-1+mod)%mod;
    sum=fast_pow(sum, n, mod);
    cout<<sum<<endl;
    return 0;
}
