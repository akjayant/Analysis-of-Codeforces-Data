#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(1337);
const int N = 1e5 + 7;

vector<int> graph[N];

set<int> d;

void dfs(int v) {
    vector<int> q;
    for (int to: d) {
        auto it = lower_bound(graph[v].begin(), graph[v].end(), to);
        if (it == graph[v].end() || *it != to) {
            q.push_back(to);
        }
    }
    for (int to: q)
        d.erase(to);
    for (int to: q)
        dfs(to);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef LOCAL
    FILE *f = freopen("input", "r", stdin);\
    freopen("output", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        d.insert(i);
    while (!d.empty()) {
        int v = *d.begin();
        d.erase(v);
        dfs(v);
        cnt++;
    }

    cout << cnt - 1;

    return 0;
}