#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define pll pair <ll, ll>
using namespace std;

const ll mod = 1e9 + 7;

ll add(ll x, ll y)
{
    if (x > mod) x %= mod;
    if (y > mod) y %= mod;
    if (x + y > mod) return x + y - mod;
    return x + y;
}

ll mul(ll x, ll y)
{
    if (x > mod) x %= mod;
    if (y > mod) y %= mod;
    if (x * y > mod) return (x * y) % mod;
    return x * y;
}

ll pot(ll x, ll y)
{
    if (y == 0) return 1;
    if (y == 1) return x;

    if (y % 2 == 0)
    {
        ll z = pot(x, y / 2);
        return mul(z, z);
    }
    else
    {
        ll z = pot(x, y / 2);
        return mul(mul(z, z), x);
    }
}

ll N, M;
ll sol;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    sol = pot(2, M) - 1;
    ll rj = pot(sol, N);

    cout << rj;
}
