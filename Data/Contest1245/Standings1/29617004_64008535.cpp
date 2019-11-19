#include <bits/stdc++.h>
#define err(args...) {}
#ifdef DEBUG
#include "_debug.cpp"
#endif
using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using lim = numeric_limits<T>;
template <typename T> istream& operator>>(istream& is, vector<T>& a) { for(T& x : a) { is >> x; } return is; }
template <bool Directed, typename TEdge, bool Index> struct graph {
    using EType = TEdge;
    vector<TEdge> edges;
    vector<vector<int>> adj;
    graph(int n) : adj(n + Index) {}
    graph(int n, int m) : graph(n) { edges.reserve(m << not Directed); }
    TEdge& operator()(int e) { return edges[e]; }
    vector<int>& operator[](int u) { return adj[u]; }
    int size() { return adj.size() - Index; }
    void add_edge(const TEdge& e) {
        adj[e.u].push_back(edges.size());
        edges.push_back(e);
        if(not Directed) {
            adj[e.v].push_back(edges.size());
            edges.push_back(e.reverse());
        }
    }
};
template <typename T> struct wedge {
    int u, v; T w;
    wedge reverse() const { return {v, u, w}; }
    friend ostream& operator<<(ostream& os, const wedge& e) {
        return os << "(" << e.u << ", " << e.v << ", " << e.w << ")";
    }
};
template <bool Directed, typename T, bool Index>
pair<T, vector<int>> mst(graph<Directed, wedge<T>, Index>& g, int s = Index) {
    vector<int> vis(g.adj.size()), p(g.adj.size(), -1);
    vector<T> d(g.adj.size(), lim<T>::max());
    priority_queue<pair<T, int>> pq({}, {{d[s] = 0, s}});
    while(not pq.empty()) {
        int u = pq.top().second; pq.pop();
        if(not vis[u]) {
            vis[u] = true;
            for(int e : g[u]) {
                if(not vis[g(e).v] and d[g(e).v] > g(e).w) {
                    pq.push({-(d[g(e).v] = g(e).w), g(p[g(e).v] = e).v});
                }
            }
        }
    }
    return {accumulate(d.begin() + Index, d.end(), T(0)), p};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> x(n + 1), y(n + 1), c(n + 1), k(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    graph<0, wedge<ll>, 0> g(n + 1, n * (n - 1) / 2);
    for(int i = 1; i <= n; i++) {
        g.add_edge({0, i, c[i]});
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            g.add_edge({i, j, (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))});
        }
    }
    auto [cost, p] = mst(g, 0);
    cout << cost << endl;
    vector<int> sources;
    for(int i = 1; i <= n; i++) {
        if(g(p[i]).u == 0) {
            sources.push_back(i);
        }
    }
    cout << sources.size() << endl;
    for(int i = 0; i < sources.size(); i++) {
        if(i) cout << " ";
        cout << sources[i];
    }
    cout << endl;
    vector<pair<int, int>> wires;
    for(int i = 1; i <= n; i++) {
        if(g(p[i]).u != 0) {
            wires.push_back({g(p[i]).u, i});
        }
    }
    cout << wires.size() << endl;
    for(auto [a, b] : wires) {
        cout << a << " " << b << endl;
    }
    return 0;
}
