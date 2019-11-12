#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=1e5+5, mod=1e9+7;

ll iterBigmod(ll b, ll n)
{
    ll ans=1;
    while(n) {
        if(n&1LL) ans=(ans*b)%mod;
        n>>=1LL;
        b=(b*b)%mod;
    }
    return ans;
}

int main()
{
    ll n,m;
    cin >> n >> m;

    ll x=iterBigmod(2,m)-1;
    if(x<0) x+=mod;

    ll ans=iterBigmod(x,n);

    cout << ans << endl;
}
