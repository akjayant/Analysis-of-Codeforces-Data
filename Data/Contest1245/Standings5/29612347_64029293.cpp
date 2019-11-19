#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2020;

int fa[N], dis[N], kl[N], x[N], y[N];

int n, tot, id[N];

bool vis[N * N];

ll ans;

struct Edge {
    int x, y;
    ll val;
} edge[N * N];

bool cmp(const Edge &a, const Edge &b) {
    return a.val < b.val;
}

int find(int x) {
    if (fa[x] == x) {
        return x;
    }
    return fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &dis[i]);
        fa[i] = i;
    }
    for (int i = 1; i <= n; i ++ ) {
        scanf("%d", &kl[i]);
        id[i] = i;
    }
    for (int i = 1; i <= n; i ++ ) {
        for (int j = i + 1; j <= n; j ++ ) {
            edge[ ++ tot] = (Edge){i, j, 1ll * (kl[i] + kl[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]))};
        }
    }
    sort(edge + 1, edge + 1 + tot, cmp);
    for (int i = 1; i <= tot; i ++ ) {
        int fx = find(edge[i].x);
        int fy = find(edge[i].y);
        if (fx == fy || (fx != fy && max(dis[id[fx]], dis[id[fy]]) <= edge[i].val)) {
            continue ;
        }
        fa[fx] = fy;
        vis[i] = 1;
        ans += edge[i].val;
        if (dis[id[fx]] < dis[id[fy]]) {
            id[fy] = id[fx];
        }
    }
    for (int i = 1; i <= n; i ++ ) {
        if (find(i) == i) {
            ans += dis[id[i]];
        }
    }
    printf("%lld\n", ans);
    ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (find(i) == i) {
            ans ++ ;
        }
    }
    printf("%lld\n", ans);
    ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (find(i) == i) {
            printf("%d ", id[i]);
        }
    }
    printf("\n");
    for (int i = 1; i <= tot; i ++ ) {
        if (vis[i]) {
            ans ++ ;
        }
    }
    printf("%lld\n", ans);
    ans = 0;
    for (int i = 1; i <= tot; i ++ ) {
        if (vis[i]) {
            printf("%d %d\n", edge[i].x, edge[i].y);
        }
    }
    return 0;
}