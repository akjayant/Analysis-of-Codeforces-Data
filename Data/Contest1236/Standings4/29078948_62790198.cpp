#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1e9+7;
ll mod_pow(ll x, ll n)
{
    ll res = 1;
    while (n>0)
    {
        if (n&1) res = res * x % MOD;
        x = x * x  % MOD;
        n >>= 1;
    }
    return res;
}
int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = mod_pow(2, m) - 1;
    ans = (ans + MOD) % MOD;
    ll tans = mod_pow(ans, n);
    cout << (tans+MOD)%MOD << endl;
}
