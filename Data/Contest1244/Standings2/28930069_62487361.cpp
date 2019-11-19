#include <bits/stdc++.h>
//haha

using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define fileio freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
vector<vector<int>> g;
vector<vector<int>> c;
vector<int> color;
vector<int> answers;
int dfs(int v, int p, int cl) {
    int ans = c[color[cl]][v];
    for (int u : g[v]) {
        if (u == p) continue;
        ans += dfs(u, v, (cl + 1) % 3);
    }
    return ans;
}

void dfs2(int v, int p, int cl) {
   answers[v] = color[cl];
    for (int u : g[v]) {
        if (u == p) continue;
        dfs2(u, v, (cl + 1) % 3);
    }
}


signed main() {
    fastio
// fileio
    int n;
    cin >> n;
    c.resize(3, vector<int> (n));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> c[i][j];
        }
    }
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;--v;--u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    bool ok = true;
    int root = 0;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() >= 3) {
            ok = false;
        }
        if (g[i].size() == 1) {
            root = i;
        }
    }
    if (!ok) {
        cout << -1;
        return 0;
    }
    color = {0, 1, 2};
    int mn = dfs(root, -1, 0);
    color = {0, 2, 1};
    int mn1 = dfs(root, -1, 0);
    color = {1, 0, 2};
    int mn2 = dfs(root, -1, 0);
    color = {1, 2, 0};
    int mn3 = dfs(root, -1, 0);
    color = {2, 0, 1};
    int mn4 = dfs(root, -1, 0);
    color = {2, 1, 0};
    int mn5 = dfs(root, -1, 0);
    int ans = min({mn, mn1, mn2, mn3, mn4, mn5});
    cout << ans << '\n';
    answers.resize(n);
    if (ans == mn) {
        color = {0, 1, 2};
        dfs2(root, -1, 0);
        for (int i = 0; i < n; ++i) {
            cout << answers[i] + 1 << ' ';
        }
        return 0;
    }
    if (ans == mn1) {
        color = {0, 2, 1};
        dfs2(root, -1, 0);
        for (int i = 0; i < n; ++i) {
            cout << answers[i] + 1 << ' ';
        }
        return 0;
    }
    if (ans == mn2) {
        color = {1, 0, 2};
        dfs2(root, -1, 0);
        for (int i = 0; i < n; ++i) {
            cout << answers[i] + 1 << ' ';
        }
        return 0;

    }
    if (ans == mn3) {
        color = {1, 2, 0};
        dfs2(root, -1, 0);
        for (int i = 0; i < n; ++i) {
            cout << answers[i] + 1 << ' ';
        }
        return 0;

    }
    if (ans == mn4) {
        color = {2, 0, 1};
        dfs2(root, -1, 0);
        for (int i = 0; i < n; ++i) {
            cout << answers[i] + 1 << ' ';
        }
        return 0;
    }
    if (ans == mn5) {
        color = {2, 1, 0};
        dfs2(root, -1, 0);
        for (int i = 0; i < n; ++i) {
            cout << answers[i] + 1 << ' ';
        }
        return 0;
    }
}