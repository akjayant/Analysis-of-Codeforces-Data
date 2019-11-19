#include <bits/stdc++.h>
using i64 = long long;

class UF {
    int *par;
    int *rank;

    public:
    UF(int size) : par(new int[size]), rank(new int[size]()) {
        for (int i = 0; i < size; i++) par[i] = i;
    }
    ~UF() { delete[] par; delete[] rank; }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (rank[x] < rank[y]) par[x] = y;
        else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
    }
};

int main() {
    int n;
    scanf("%d", &n);
    std::vector<std::pair<i64, i64>> city;
    std::vector<i64> c(n), k(n);
    for (int i = 0; i < n; i++) {
        i64 x, y;
        scanf("%lld%lld", &x, &y);
        city.emplace_back(x, y);
    }
    std::vector<std::tuple<i64, int, int>> edges;
    for (auto &e : c) scanf("%lld", &e);
    for (auto &e : k) scanf("%lld", &e);

    for (int i = 0; i < n; i++) edges.emplace_back(c[i], i, n);
    auto f = [](auto n) { return n >= 0 ? n : -n; };
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        i64 dist = f(city[i].first - city[j].first) + f(city[i].second - city[j].second);
        edges.emplace_back((k[i] + k[j]) * dist, i, j);
    }

    std::sort(edges.begin(), edges.end());
    UF uft(n + 1);
    i64 ret = 0;
    std::vector<std::pair<int, int>> es;
    std::vector<int> vs;
    for (auto [cost, i, j] : edges) {
        if (uft.same(i, j)) continue;
        uft.unite(i, j);
        ret += cost;
        if (j == n) vs.push_back(i);
        else es.emplace_back(i, j);
    }

    printf("%lld\n", ret);
    printf("%ld\n", vs.size());
    for (auto v : vs) printf("%d ", v + 1);
    printf("\n%ld\n", es.size());
    for (auto [i, j] : es) printf("%d %d\n", i + 1, j + 1);

    return 0;
}
