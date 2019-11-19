#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
ll a[110000];

ll myPow(ll x, ll y)
{
    if(y == 0) return 1;
    if(y == 1) return x;
    ll ans = myPow(x, y / 2);
    if(y % 2 == 0) return ans * ans % mod;
    else return ans * ans % mod * x % mod;
}

int main()
{
    ll n, m; cin >> n >> m;
    a[0] = a[1] = 1;
    for(int i = 2; i <= 100000; i ++)
    {
        a[i] = a[i - 1] + a[i - 2];
        a[i] %= mod;
    }
    ll ans = (a[n] + a[m] - 1) % mod;
    if(ans < 0) ans += mod;
    cout << ans * 2 % mod;
    return 0;
}
