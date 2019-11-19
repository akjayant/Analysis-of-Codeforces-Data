#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(1337);

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef LOCAL
    FILE *f = freopen("input", "r", stdin);\
    freopen("output", "w", stdout);
#endif

    ll n, _n;
    cin >> n;
    _n = n;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    vector<ll> dd;
    dd.reserve(2 * sqrt(n) + 7);

    for (ll i = 2; i * i <= n; ++i) {
        if ((n % i) == 0) {
            while ((n % i) == 0) n /= i;
            dd.push_back(i);
            if (n != 1)
                dd.push_back(n);
        }
    }

    if (n != 1)
        dd.push_back(n);

    n = _n;

    if (dd.size() > 1) {
        cout << 1;
    } else {
        cout << dd[0];
    }

    return 0;
}