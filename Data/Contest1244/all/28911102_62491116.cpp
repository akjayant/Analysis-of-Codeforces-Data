// qdd on Oct 13, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class T>
inline bool updmin(T& a, T b) {
    return a > b ? a = b, 1 : 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int> > a(n + 1, vector<int>(3));
    vector<vector<int> > G(n + 1);
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i][1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i][2];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++, d[v]++;
        G[u].push_back(v);
        G[v].push_back(u);
        if (d[u] > 2 || d[v] > 2) {
            cout << "-1\n";
            return 0;
        }
    }
    int rt = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            rt = i;
            break;
        }
    }
    vector<int> order;
    function<void(int, int)> dfs = [&](int u, int pa) {
        order.push_back(u);
        for (int v : G[u])
            if (v != pa) dfs(v, u);
    };
    dfs(rt, 0);
    vector<int> p = {0, 1, 2}, P, res(n + 1);
    ll Ans = LLONG_MAX;
    do {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[order[i]][p[i % 3]];
        }
        if (updmin(Ans, ans)) {
            P = p;
        }
    } while (next_permutation(p.begin(), p.end()));
    for (int i = 0; i < n; i++) {
        res[order[i]] = P[i % 3];
    }
    cout << Ans << '\n';
    for (int i = 1; i <= n; i++) {
        cout << res[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;
}