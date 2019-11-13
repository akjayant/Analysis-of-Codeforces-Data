#include <bits/stdc++.h>
using namespace std;

typedef vector<int> veci;
typedef pair<int, int> pii;
typedef vector<pii> vecii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vecl;
typedef vector<pll> vecll;
#define EPS (1e-9)
#define fi first
#define se second
#define endl '\n'

ll const MOD = ll(1e9 + 7);

ll power(ll x, ll y) {
    ll res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) res = (res * x) % MOD;

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll each = power(2,m) + MOD - 1;
    each %= MOD;

    cout << power(each, n) << endl;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL_TEST
    (void)argc;
    const string strpath = string(argv[0]) + string("-test.in");
    freopen(strpath.c_str(), "r", stdin);
    int tcs;
    cin >> tcs;
    while (tcs-- > 0)
#endif
        solve();
}
