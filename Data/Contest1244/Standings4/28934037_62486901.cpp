#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];
vector <int> deg(N, 0);
vector <int> path;

void dfs(int v, int par) {
    path.push_back(v);
    for (int u : g[v]) {
        if (u != par) {
            dfs(u, v);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector <int> c[3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            c[i].push_back(x);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool good = true;
    for (int i = 0; i < n; i++) {
        good &= (deg[i] <= 2);
    }
    if (!good) {
        cout << -1 << '\n';
        return;
    }
    int st = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            st = i;
        }
    }
    dfs(st, -1);
    vector <int> color(n, 0);
    ll res = 1e16 + 7;
    vector <int> all_perm = {0, 1, 2};
    do {
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            cur += c[all_perm[i % 3]][path[i]];
        }
        if (cur < res) {
            res = cur;
            for (int i = 0; i < n; i++) {
                color[path[i]] = all_perm[i % 3];
            }
        }
    } while (next_permutation(all_perm.begin(), all_perm.end()));
    cout << res << '\n';
    for (int i = 0; i < n; i++) {
        cout << color[i] + 1 << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
