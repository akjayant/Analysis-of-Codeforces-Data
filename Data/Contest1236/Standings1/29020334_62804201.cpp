#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007

ll bigMod(ll x, ll a)
{
    if(a == 0) return 1LL;
    if(a == 1) return x;
    ll ret = bigMod(x, a/2);
    ret = (ret*ret)%MOD;
    if(a&1) ret = (ret*x)%MOD;
    return ret;
}

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll ans = (bigMod(2, m) - 1)%MOD;
    if(ans < 0) ans += MOD;
    ans = bigMod(ans, n);
    cout << ans;
}