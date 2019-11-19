#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

struct disj {
    int par[N];
    void init (int n) {
        iota(par + 1, par + n + 1, 1);
    }

    int Find (int x) {
        return par[x] == x ? x : par[x] = Find(par[x]);
    }

    bool same (int x, int y) {
        return Find(x) == Find(y);
    }

    void join (int x, int y) {
        x = Find(x); y = Find(y);
        if (x == y) return;
        par[y] = x;
    }
} dsu;

int n, x[N], y[N], c[N], k[N];
vector <pair <long long, pair <int, int> > > edges;
vector <int> stations;
vector <pair <int, int> > connections;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
    dsu.init(n + 1);
    for (int i = 1; i <= n; i++) edges.push_back({c[i], {i, n + 1}});
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long cost = 1LL * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
            edges.push_back({cost, {i, j}});
        }
    }

    sort(edges.begin(), edges.end());
    long long ans = 0;
    for (auto i: edges) {
        long long w = i.first;
        int u = i.second.first, v = i.second.second;
        if (dsu.same(u, v)) continue;
        dsu.join(u, v);
        ans += w;

        if (v == n + 1) stations.push_back(u);
        else connections.push_back({u, v});
    }

    printf("%lld\n", ans);
    printf("%d\n", (int)stations.size());
    for (auto i: stations) printf("%d ", i);
    printf("\n%d\n", (int)connections.size());
    for (auto i: connections) printf("%d %d\n", i.first, i.second);
    return 0;
}
