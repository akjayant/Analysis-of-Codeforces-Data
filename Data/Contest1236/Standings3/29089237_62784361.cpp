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

const int  MAX   = (int)(2e5) + 7;
const int  MOD   = (int)(1e9) + 7;
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

int t;
int a, b, c;

void solve();

signed main() {
    boot_up();

    cin >> t;
    while (cin >> a >> b >> c) solve();
}

void solve() {
    #ifdef TEST
        cout << "-------TEST-------" << endl;
    #endif

    int ans1 = 0, ans2 = 0;

    int a1 = a, b1 = b, c1 = c;

    while (a >= 1 && b >= 2) {
        a -= 1;
        b -= 2;
        ++ans1;
    }

    while (b >= 1 && c >= 2) {
        b -= 1;
        c -= 2;
        ++ans1;
    }

    while (b1 >=1 && c1 >= 2) {
        b1 -= 1;
        c1 -= 2;
        ++ans2;
    }

    while (a1 >= 1 && b1 >= 2) {
        a1 -= 1;
        b1 -= 2;
        ++ans2;
    }

    cout << 3 * max(ans1, ans2) << '\n';
}