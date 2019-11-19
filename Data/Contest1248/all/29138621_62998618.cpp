// qdd on Oct 20, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1e6 + 7;

int say(bool tag) {
    cout << (tag ? "Yes\n" : "No\n");
    return 0;
}

vector<int> G[MAXN], scc[MAXN];
int dfn[MAXN], low[MAXN], clk, tot, color[MAXN];

void tarjan(int u) {
    static int st[MAXN], p;
    static bool in[MAXN];
    dfn[u] = low[u] = ++clk;
    st[p++] = u;
    in[u] = true;
    for (int v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++tot;
        for (;;) {
            int x = st[--p];
            in[x] = false;
            color[x] = tot;
            scc[tot].push_back(x);
            if (x == u) break;
        }
    }
}
void init(int n) {
    tot = clk = 0;
    for (int i = 0; i <= n; i++) {
        G[i].clear();
        scc[i].clear();
    }
    fill(dfn, dfn + n + 1, 0);
    fill(low, low + n + 1, 0);
    fill(color, color + n + 1, 0);
}

void solve() {
    int n, m, u, v;
    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        if (u != v) {
            G[u].push_back(v);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    bool no_sol = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] != color[1]) no_sol = false;
    }
    if (no_sol) {
        say(0);
        return;
    }
    vector<int> A = scc[1], B;
    for (int i = 2; i <= tot; i++) {
        for (int x : scc[i]) B.push_back(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    say(1);
    cout << A.size() << ' ' << B.size() << '\n';
    for (int x : A) cout << x << ' ';
    cout << '\n';
    for (int x : B) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
