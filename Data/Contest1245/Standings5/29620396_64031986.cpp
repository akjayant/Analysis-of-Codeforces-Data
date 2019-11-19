#include <bits/stdc++.h>

typedef long long ll;

const int N = 2000 + 5;

struct Edge {
    ll x, y, w;

    Edge() {}
    Edge(ll x, ll y, ll w) : x(x), y(y), w(w) {}

    bool operator<(const Edge &other) const {
        return w < other.w;
    }
} e[N * N];

int n, end;
int fa[N];
ll x[N], y[N], c[N], k[N], sum;

int find(int x) {
    return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}

inline bool merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return false;
    else {
        fa[fx] = fy;
        return true;
    }
}

inline void addEdge(ll x, ll y, ll w) {
    end++;
    e[end] = Edge(x, y, w);
}

std::vector<int> ans1;
std::vector< std::pair<int, int> > ans2;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%I64d %I64d", &x[i], &y[i]);
    for (int i = 1; i <= n; i++) scanf("%I64d", &c[i]);
    for (int i = 1; i <= n; i++) scanf("%I64d", &k[i]);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) addEdge(0, i, c[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            addEdge(i, j, (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])));
        }
    }
    std::sort(e + 1, e + end + 1);
    for (int i = 1; i <= end; i++) {
        int u = e[i].x, v = e[i].y;
        if (merge(u, v)) {
            sum += e[i].w;
            if (u != 0 && v != 0) ans2.push_back(std::make_pair(u, v));
            else {
                if (u != 0) ans1.push_back(u);
                if (v != 0) ans1.push_back(v);
            }
        }
    }
    printf("%I64d\n", sum);
    printf("%d\n", (int)ans1.size());
    for (int i = 0; i < ans1.size(); i++) {
        printf("%d ", ans1[i]);
    }
    puts("");
    printf("%d\n", (int)ans2.size());
    for (int i = 0; i < ans2.size(); i++) {
        printf("%d %d\n", ans2[i].first, ans2[i].second);
    }
    return 0;
}