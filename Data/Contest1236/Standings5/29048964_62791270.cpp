#include <bits/stdc++.h>
#define endl "\n"
#define INF (int)1e9
#define ll long long
#define ull unsigned long long

#define MOD 1000000007

using namespace std;

ll powmod(ll a, ll b)
{
    a %= MOD;
    ll ans = 1LL;
    while (b > 0)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = powmod(2, m) - 1;
    ans = powmod(ans, n);
    cout << ans << endl;
}