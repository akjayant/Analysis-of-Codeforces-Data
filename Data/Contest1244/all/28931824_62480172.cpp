#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> g;
vector<int> c1, c2, c3;
vector<int> used;

int dfs(int v) {
    used[v] = 1;
    int res = 1;
    for (int i : g[v]) {
        if (used[i])
            continue;
        res += dfs(i);
    }
    return res;
}

vector<int> answer;

int dfs2(int v, int col, int p = -1, bool answ = false) {
    int res = 0;
    if (answ)
        answer[v] = col;
    if (col == 1)
        res += c1[v];
    if (col == 2)
        res += c2[v];
    if (col == 3)
        res += c3[v];
    int cur = col + 1;
    if (cur == 4)
        cur = 1;
    for (int i : g[v]) {
        if (i == p)
            continue;
        res += dfs2(i, cur, v, answ);
    }
    return res;
}

int dfs3(int v, int col, int p = -1, bool answ = false) {
    int res = 0;
    if (answ)
        answer[v] = col;
    if (col == 1)
        res += c1[v];
    if (col == 2)
        res += c2[v];
    if (col == 3)
        res += c3[v];
    int cur = col - 1;
    if (cur == 0)
        cur = 3;
    for (int i : g[v]) {
        if (i == p)
            continue;
        res += dfs3(i, cur, v, answ);
    }
    return res;
}

vector<int> us;

void cl(int v) {
    us[v] = 1;
    for (int i : g[v]) {
        if (us[i])
            continue;
        cl(i);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    g.resize(n);
    c1.resize(n);
    c2.resize(n);
    c3.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> c1[i];
    for (int i = 0; i < n; ++i)
        cin >> c2[i];
    for (int i = 0; i < n; ++i)
        cin >> c3[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i].size() > 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    used.resize(n);
    for (int i = 0; i < n; ++i)
        if (!used[i] && g[i].size() == 1)
            dfs(i);
        for (int i = 0; i < n; ++i)
        if (!used[i])
            if (dfs(i) % 3) {
                cout << -1 << endl;
                return 0;
            };
    us.resize(n);
    answer.resize(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!us[i] && g[i].size() == 1) {
            int r1 = dfs2(i, 1);
            int r2 = dfs2(i, 2);
            int r3 = dfs2(i, 3);
            int r4 = dfs3(i, 1);
            int r5 = dfs3(i, 2);
            int r6 = dfs3(i, 3);
            int mn = min({r1, r2, r3, r4, r5, r6});
            ans += mn;
            if (r1 == mn)
                dfs2(i, 1, -1, true);
            else if (r2 == mn)
                dfs2(i, 2, -1, true);
            else if (r3 == mn)
                dfs2(i, 3, -1, true);
            else if (r4 == mn)
                dfs3(i, 1, -1, true);
            else if (r5 == mn)
                dfs3(i, 2, -1, true);
            else if (r6 == mn)
                dfs3(i, 3, -1, true);
            cl(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!us[i]) {
            int r1 = dfs2(i, 1);
            int r2 = dfs2(i, 2);
            int r3 = dfs2(i, 3);
            int r4 = dfs3(i, 1);
            int r5 = dfs3(i, 2);
            int r6 = dfs3(i, 3);
            int mn = min({r1, r2, r3, r4, r5, r6});
            ans += mn;
            if (r1 == mn)
                dfs2(i, 1, -1, true);
            else if (r2 == mn)
                dfs2(i, 2, -1, true);
            else if (r3 == mn)
                dfs2(i, 3, -1, true);
            else if (r4 == mn)
                dfs3(i, 1, -1, true);
            else if (r5 == mn)
                dfs3(i, 2, -1, true);
            else if (r6 == mn)
                dfs3(i, 3, -1, true);
            cl(i);
        }
    }
    cout << ans << endl;
    for (int i : answer)
        cout << i << " ";
    return 0;
}
