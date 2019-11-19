#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 69;
vector<int> g[MAXN];
int n, m;

set<int> used;
int used1[MAXN];
int ans = 0;

void dfs(int v) {
    used.erase(v);
    for (int to = 1; to < g[v].size(); ++to) {
        int pr = g[v][to - 1];
        int cur = g[v][to];
        auto l = used.lower_bound(pr + 1);
        auto r = used.upper_bound(cur - 1);
        if (l != r) {
            int u = *l;
            used.erase(u);
            ans++;
            dfs(u);
        }
    }
}

int main() {
//     freopen("negcycle.in", "r", stdin);
//     freopen("negcycle.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int fr, to;
        cin >> fr >> to;
        g[fr - 1].push_back(to - 1);
        g[to - 1].push_back(fr - 1);
    }
    for (int i = 0; i < n; ++i) {
        g[i].push_back(-1);
        g[i].push_back(n);
        g[i].push_back(i);
        sort(g[i].begin(), g[i].end());
    }
    for (int i = 0; i < n; ++i) {
        used.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        if (used.find(i) != used.end()) {
            dfs(i);
        }
    }
    cout << n - 1 - ans;
}