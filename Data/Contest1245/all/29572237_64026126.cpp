#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 2005;

int a[N], b[N], c[N], d[N];

int p[N];
int find(int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
}
vector<int> ans;
vector<pair<int, int>> e;
bool vis[N];
LL sum = 0;
int n;

struct Edge {
    int u, v;
    LL w;
} g[N * N + N];
bool cmp(const Edge &p1, const Edge &p2) {
    return p1.w < p2.w;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) p[i] = i;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            g[m] = {i, j, (LL)(abs(a[i] - a[j]) + abs(b[i] - b[j])) * (d[i] + d[j])};
            m++;
        }
    }
    for (int i = 0; i < n; i++) {
        g[m++] = {i, n, c[i]};
    }
    sort(g, g + m, cmp);
    for (int i = 0; i < m; i++) {
        int x = find(g[i].u), y = find(g[i].v);
        if (x != y) {
            p[x] = y;
            sum += g[i].w;
            if (g[i].u == n) {
                ans.push_back(g[i].v);
            } else if (g[i].v == n) {
                ans.push_back(g[i].u);
            } else {
                e.push_back({g[i].u, g[i].v});
            }
        }
    }
    printf("%lld\n%d\n", sum, ans.size());
    for (auto x : ans) {
        printf("%d ", x + 1);
    }
    puts("");
    printf("%d\n", e.size());
    for (auto x : e) {
        printf("%d %d\n", x.first + 1, x.second + 1);
    }
    return 0;
}
