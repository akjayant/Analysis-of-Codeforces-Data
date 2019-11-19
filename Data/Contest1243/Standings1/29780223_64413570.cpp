#include <bits/stdc++.h>
using namespace std;

void dfsm(vector<vector<int>> &g, int v, vector<int> &used) {
    used[v] = 1;
    for (int i = 0; i < g.size(); ++i) {
        if (g[v][i] && !used[i]) {
            dfsm(g, i, used);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    if (n <= 4000) {
//    if (false) {
        vector<vector<int>> g(n, vector<int>(n));
        vector<int> used(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j)
                    g[i][j] = 1;
            }
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u][v] = g[v][u] = 0;
        }
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                ++ans;
                dfsm(g, i, used);
            }
        }
        cout << ans << endl;
    }
    else {
        vector<vector<int>> g1(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
        vector<int> tr(n, -1);
        vector<int> rtr(n, -1);
        int id = 0;
        for (int i = 0; i < n; ++i) {
            if (g1[i].size() > n / 2) {
                rtr[id] = i;
                tr[i] = id++;
            }
        }
        vector<int> cost(id, 1);
        vector<vector<int>> g(id, vector<int>(id));
        for (int i = 0; i < id; ++i) {
            for (int j = 0; j < id; ++j)
                if (i != j)
                    g[i][j] = 1;
        }
        for (int i = 0; i < id; ++i) {
            int now = n - id;
            for (int j = 0; j < g1[rtr[i]].size(); ++j) {
                if (tr[g1[rtr[i]][j]] == -1)
                    --now;
                else
                    g[i][tr[g1[rtr[i]][j]]] = 0;
            }
            if (now)
                cost[i] = 0;
        }
        vector<int> used(id);
        for (int i = 0; i < id; ++i) {
            if (cost[i] == 0 && !used[i]) {
                dfsm(g, i, used);
            }
        }
        int ans = 0;
        for (int i = 0; i < id; ++i) {
            if (!used[i]) {
                ++ans;
                dfsm(g, i, used);
            }
        }
        cout << ans << endl;
    }
    return 0;
}