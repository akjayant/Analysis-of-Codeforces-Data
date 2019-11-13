
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()

#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)
#define D(x) get<3>(x)

mt19937 gen(228);

#ifdef DEBUG
#define dbg(x) cout << "[dbg " << __LINE__ << "] " << x << endl
#else
#define dbg(x) ((void)0)
#endif

constexpr ll MOD = 1'000'000'007;

ll mpow(ll a, ll p, ll m) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        p >>= 1;
    }
    return res;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cout << mpow(((mpow(2, m, MOD) - 1 + MOD) % MOD), n, MOD) % MOD << "\n";

    return 0;
}
