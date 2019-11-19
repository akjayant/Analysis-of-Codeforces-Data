#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define rep(i, a, b) for(int i = a; i < b; ++i)

int debug = 0;

const int N = 4e5, inf = 1e16;

int n, c[3][N], ans[N], cur[N], was[N];
int mincost = inf, sv, v2, v3;
vector <int> g[N];

void dfs(int v, int c1, int c2) {
    if (was[v]) return;
    was[v] = 1;
    cur[v] = (0 ^ 1 ^ 2 ^ c1 ^ c2);
    for (int u : g[v]) {
        if (was[u] == 1) continue;
        dfs(u, c2, cur[v]);
    }
}

void relax(int c1, int c2) {
    int curcost = 0;
    fill(cur, cur + n, -1);
    fill(was, was + n, 0);
    cur[sv] = c1;
    cur[v2] = c2;
    was[sv] = 1;
    was[v2] = 1;
    dfs(v3, c1, c2);

    curcost = 0;
    rep(i, 0, n) {
        curcost += c[cur[i]][i];
    }
    if (curcost < mincost) {
        mincost = curcost;
        rep(i, 0, n) {
            ans[i] = cur[i];
        }
    }
}

main() {
    cin >> n;
    rep(j, 0, 3) rep(i, 0, n) cin >> c[j][i];
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    rep(i, 0, n) {
        if (g[i].size() > 2) {
            puts("-1");
            return 0;
        }
        if (g[i].size() == 1) {
            sv = i;
            v2 = g[i][0];
            v3 = (g[v2][0] != sv) ? g[v2][0] : g[v2][1];
        }
    }

    if (debug) {
        cerr << "   v123=" << sv << ' ' << v2 << ' ' << v3 << ' ';
    }
    mincost = inf;
    rep(i, 0, 3) rep(j, 0, 3) if (i != j) relax(i, j);
    cout << mincost << '\n';
    rep(i, 0, n) {
        cout << ans[i]+1 << ' ';
    }
}