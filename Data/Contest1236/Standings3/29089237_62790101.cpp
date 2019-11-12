#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(a) (int)(a).size()
#define dbg(a) cout << #a << " := " << a << '\n'

using namespace std;
using ll = long long;
using ld = long double;

const  ll MAX    = (ll)(2e5) + 7;
const  ll MOD   =  (ll)(1e9) + 7;
const int  INF_I = (int)(1e9) + 7;
const  ll INF_LL =     (ll)(1e18);

template <typename T> void init(vector<T> & v, int _size, T value = 0) {
    v.assign(_size, value);
}

template <typename T> void info(T & v) {
    for (const auto & el : v) {
        cout << el << ' ';
    }
    cout << '\n';
}

template <typename T> inline bool chkmin(T & a, T b) { if (a > b) { a = b; return true; } return false; }

template <typename T> inline bool chkmax(T & a, T b) { if (a < b) { a = b; return true; } return false; }

inline void boot_up() {
    #ifdef TEST
        freopen(  "input.in", "r",  stdin);
        freopen("output.out", "w", stdout);
    #endif
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
}

ll n, m;

void solve();
ll bin_pow(ll a, int n);
void sub(ll & a, ll b);

signed main() {
    boot_up();

    while (cin >> n >> m) solve();
}

void solve() {
    #ifdef TEST
        cout << "-------TEST-------" << endl;
    #endif

    ll ans = bin_pow(2LL, m);
    sub(ans, 1);

    cout << bin_pow(ans, n) << '\n';
}

ll bin_pow(ll a, int n) {
    if (n == 0) {
        return 1;
    }

    if (n % 2) {
        return (a * bin_pow(a, n - 1)) % MOD;
    }

    ll res = bin_pow(a, n / 2);

    return (res * res) % MOD;
}

void sub(ll & a, ll b) {
    a = ((a - b) % MOD + MOD) % MOD;
}