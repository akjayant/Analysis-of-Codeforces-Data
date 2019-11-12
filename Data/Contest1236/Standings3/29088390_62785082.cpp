#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

ll poww(ll x, ll n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        ll a = poww(x, n / 2);
        return (a * a) % mod;
    }
    return (poww(x, n - 1) * x) % mod;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll x = poww(2, m) - 1;
    x %= mod;
    while (x < 0)
        x += mod;
    x = poww(x, n);
    x %= mod;
    while (x < 0)
        x += mod;
    cout << x;
}
