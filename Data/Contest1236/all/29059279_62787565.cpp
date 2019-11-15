// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;
template <typename T = vii>
using vec = vector<T>;

const ll INF = 1e18, MOD = 1e9 + 7;

const int MAX = 1e6;

constexpr inline ll pow_mod(ll a, ll n, const ll p = MOD) {
    ll res = 1;
    a %= p;
    for (; n; (a *= a) %= p, n >>= 1) {
        if (n & 1) {
            (res *= a) %= p;
        }
    }
    return res;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);

    ll n, m;
    cin >> n >> m;
    const ll res = pow_mod(pow_mod(2, m) + MOD - 1, n);
    cout << res << '\n';
}