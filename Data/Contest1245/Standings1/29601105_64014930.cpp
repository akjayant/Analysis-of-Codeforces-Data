#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int a, b;
    long long w;
};

struct union_find {
    vector<int> uf;
    union_find(int N) {
        uf.resize(N + 1, -1);
    }

    int find(int i) {
        if (uf[i] < 0) return i;
        else return uf[i] = find(uf[i]);
    }

    void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;
        if (uf[a] < uf[b]) {
            uf[b] = a;
        } else if (uf[a] > uf[b]) {
            uf[a] = b;
        } else {
            uf[b] = a;
            uf[a]--;
        }
    }
};

int main() {
    int N;
    scanf("%d", &N);

    vector<long long> x(N + 1), y(N + 1), k(N + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    vector<edge> edges;
    for (int i = 1; i <= N; ++i) {
        long long c;
        scanf("%lld", &c);
        edges.push_back({0, i, c});
    }
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &k[i]);
        for (int j = 1; j < i; ++j) {
            long long dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            edges.push_back({i, j, dist * (k[i] + k[j])});
        }
    }

    sort(edges.begin(), edges.end(), [](edge &a, edge &b) {
        return a.w < b.w;
    });

    union_find uf(N);
    vector<int> power_station;
    vector<pair<int, int>> connection;
    long long cost = 0;
    for (int i = 0; i < edges.size(); ++i) {
        if (uf.find(edges[i].a) == uf.find(edges[i].b)) {
            continue;
        }

        uf.merge(edges[i].a, edges[i].b);

        cost += edges[i].w;
        if (edges[i].a == 0) {
            power_station.push_back(edges[i].b);
        } else {
            connection.push_back({edges[i].a, edges[i].b});
        }
    }

    printf("%lld\n", cost);
    printf("%d\n", (int) power_station.size());
    for (int i = 0; i < power_station.size(); ++i) {
        printf("%d", power_station[i]);
        if (i == power_station.size() - 1) printf("\n");
        else printf(" ");
    }
    printf("%d\n", (int) connection.size());
    for (int i = 0; i < connection.size(); ++i) {
        printf("%d %d\n", connection[i].first, connection[i].second);
    }

    return 0;
}
