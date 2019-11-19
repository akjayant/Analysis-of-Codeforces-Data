#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-O3")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

#define pb push_back
#define F first
#define S second
#define lll long long
#define lld long double

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree <T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());

const int N = 2e5 + 229;
const lll M = 1e18 + 3;
const lll M2 = 1e9 + 9;
const int mod = 998244353;
const int rx[4] = {1, -1, 0, 0};
const int ry[4] = {0, 0, 1, -1};
const lld eps = 1e-18;
const double pi = acos(-1.0);

vector < int > g[N];

lll c[N][3];

int ans[N];

int root;

lll dfs(int v, int c1, int c2, int p = -1) {
    lll ans = c[v][c1];
    int c3;
    for (c3 = 0; c3 < 3; ++c3) {
        if (c3 != c1 && c3 != c2) {
            break;
        }
    }
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        ans += dfs(to, c2, c3, v);
    }
    return ans;
}

void go(int v, int c1, int c2, int p = -1) {
    ans[v] = c1;
    int c3;
    for (c3 = 0; c3 < 3; ++c3) {
        if (c3 != c1 && c3 != c2) {
            break;
        }
    }
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        go(to, c2, c3, v);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
//    freopen("game.in", "r", stdin);
//    freopen("game.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int f = 0; f < 3; ++f) {
        for (int i = 0; i < n; ++i) {
            cin >> c[i][f];
        }
    }
    int x, y;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        --x;
        --y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for (int i = 0; i < n; ++i) {
        if (int(g[i].size()) == 1) {
            root = i;
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (int(g[i].size()) > 2) {
            cout << -1;
            return 0;
        }
    }
    pair < lll, pair < int, int > > best, now;
    best.F = 1e18;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) {
                continue;
            }
            now = {dfs(root, i, j), {i, j}};
            best = min(best, now);
        }
    }
    cout << best.F << '\n';
    go(root, best.S.F, best.S.S);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    return 0;
}
