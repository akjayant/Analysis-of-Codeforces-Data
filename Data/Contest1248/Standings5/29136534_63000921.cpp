#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7, N=1e5+5;
ll n, m, dp[N][3][3];
ll power(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
ll go(ll indx, ll a, ll b)
{
    if (indx==n)
        return 1;
    ll &ret=dp[indx][a][b];
    if (~ret)
        return ret;
    ret=0;
    if (a<=1)
        ret=(ret+go(indx+1, a+1, 0))%mod;
    if (b<=1)
        ret=(ret+go(indx+1, 0, b+1))%mod;
    return ret%mod;
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    ll ans=go(0, 0, 0);
    swap(m, n);
    memset(dp, -1, sizeof dp);
    cout << (ans+go(0, 0, 0)-2)%mod;
    return 0;
}
