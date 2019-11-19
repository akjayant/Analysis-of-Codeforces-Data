#include <bits/stdc++.h>
#define REP(i, start, end) for (int i=start, i##Len=(end); i < i##Len; ++i)
#define REPR(i, start, end) for (int i=start, i##Len=(end); i > i##Len; --i)
using ll = int64_t;
using namespace std;
using AdjacencyList = vector<vector<int>>;

struct edge {
    int u;
    int v;
    ll cost;
};

vector<edge> edges;
int V;

// Union Find
struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);

        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    int size(int x) { return -data[root(x)]; }
};

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

int kruskal() {
    sort(edges.begin(), edges.end(), comp);
    UnionFind uf = UnionFind(V);
    ll res = 0;
    vector<int> build;
    vector<pair<int, int>> connect;

    for (auto e : edges) {
        if (uf.unionSet(e.u, e.v)) {
            res += e.cost;
            if (e.v == 0) build.emplace_back(e.u);
            else connect.emplace_back(e.u, e.v);
        }
    }

    cout << res << "\n";
    cout << build.size() << "\n";
    REP(i, 0, build.size()-1) cout << build[i] << " ";
    cout << build[build.size()-1] << "\n";
    cout << connect.size() << "\n";
    REP(i, 0, connect.size()) cout << connect[i].first << " " << connect[i].second << "\n";
    return res;
}

int main() {
    using namespace std;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll x, y;
    cin >> V;
    vector<pair<ll, ll>> pos;
    REP(i, 0, V) {
        cin >> x >> y;
        pos.emplace_back(x, y);
    }
    vector<ll> c_cost(V), k_cost(V);
    REP(i, 0, V) cin >> c_cost[i];
    REP(i, 0, V) cin >> k_cost[i];

    REP(i, 0, V) {
        REP(j, i+1, V) {
            edges.push_back(edge {i+1, j+1,
                (abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second)) * (k_cost[i]+k_cost[j])
            });
        }
        edges.push_back(edge {i+1, 0, c_cost[i]});
    }
    ++V;
    kruskal();
    return 0;
}
