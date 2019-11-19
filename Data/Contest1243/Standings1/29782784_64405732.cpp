#include <bits/stdc++.h>
using namespace std;
 
struct DSU {
    int n;
    vector<int> p;
    DSU(int n_) {
        n = n_;
        p.assign(n, -1);
    }
 
    int get(int u) { return p[u] < 0 ? u : p[u] = get(p[u]); }
 
    void unite(int u, int v) {
        u = get(u), v = get(v);
        if(u == v) return;
        if(p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u;
    }
};
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int u = 0; u < n; ++u) sort(adj[u].begin(), adj[u].end());
    
    DSU dsu(n);
    mt19937 rng(time(NULL));
 
    const int SQRT_N = sqrt(n);
    for(int u = 0; u < n; ++u) {
        if(adj[u].size() <= SQRT_N) {
            int T = 100;
            while(T--) {
                int v = rng() % n;
                if(u == v || binary_search(adj[u].begin(), adj[u].end(), v)) continue;
                dsu.unite(u, v);
            }
        } else {
            vector<int> v(n);
            iota(v.begin(), v.end(), 0);
            vector<int> diff;
            std::set_difference(v.begin(), v.end(), adj[u].begin(), adj[u].end(), 
                        std::inserter(diff, diff.begin()));
            for(int x : diff) {
                dsu.unite(x, u);
            }
        }
    }
    
    int ans = 0;
    for(auto& x : dsu.p) {
        if(x < 0) ans += 1;
    }
    cout << ans - 1 << '\n';
}
