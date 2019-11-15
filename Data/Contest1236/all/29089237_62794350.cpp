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

int n;
int chto[401][401];

void solve();

signed main() {
    boot_up();

    while (cin >> n) solve();
}

void solve() {
    #ifdef TEST
        cout << "-------TEST-------" << endl;
    #endif

    int curr = 1;
    int nechto = 0;

    for (int i = 0; i < n; ++i) {
        if (!nechto) {
            for (int j = 0; j < n; ++j) {
                chto[j][i] = curr++;
            }
        }
        else {
            for (int j = n - 1; j >= 0; --j) {
                chto[j][i] = curr++;
            }
        }

        nechto = 1 - nechto;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << chto[i][j] << ' ';
        }
        cout << '\n';
    }
}