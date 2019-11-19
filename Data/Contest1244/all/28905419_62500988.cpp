// #pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vii = vector<int>;
using pii = pair<int, int>;
template <typename T = vii>
using vec = vector<T>;

const ll INF = 1e18, MOD = 1e9 + 7;

const int MAX = 1e6;

vec<vll> c;
vii color;
vec<> adj;

ll dfs(int u, int p, int x, int y) {
    for (int i = 0; i < 3; i++) {
        if (i != x and i != y) color[u] = i;
    }
    ll res = c[u][color[u]];
    for (int v : adj[u]) {
        if (v != p) {
            res += dfs(v, u, color[u], x);
        }
    }
    return res;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("in.in", "r", stdin);

    int n;
    cin >> n;
    c.assign(n, vll(3));
    adj.resize(n);
    color.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i][0];
    }       
    for (int i = 0; i < n; i++) {
        cin >> c[i][1];
    }       
    for (int i = 0; i < n; i++) {
        cin >> c[i][2];
    }       
    vii degree(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++, degree[v]++;
    }
    if (any_of(degree.begin(), degree.end(), [](int val) { return val >= 3; })) {
        cout << "-1\n";
        return 0;
    }
    int leaf = distance(degree.begin(), min_element(degree.begin(), degree.end()));
    

    ll cur = INF;
    int x, y;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            ll val = dfs(leaf, -1, i, j);
            if (val < cur) {
                cur = val;
                x = i, y = j;
            }
        }
    }
    cout << dfs(leaf, -1, x, y) << '\n';

    for (auto e : color) {
        cout << e + 1 << ' ';
    }
    cout << '\n';
}