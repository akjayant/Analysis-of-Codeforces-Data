// Crt. 2019-10-13  17:04:28
#include <bits/stdc++.h>
using namespace std;

#define N 200005

int n;
int a[N], c[5][N], d[N], cnt[N], colo[N];
int tot, fir[N], nxt[N << 1], to[N << 1];

inline void addE(int u, int v) {
    nxt[++tot] = fir[u], fir[u] = tot, to[tot] = v;
}

int get(int x, int y) {
    if (x > y) swap(x, y);
    if (x == 1 && y == 2) return 3;
    if (x == 1 && y == 3) return 2;
    if (x == 2 && y == 3) return 1;
}

int dfn[N], top;

void dfs(int u, int p) {
    dfn[++top] = u;
    for (int i = fir[u], v; i; i = nxt[i]) {
        v = to[i];
        if (v == p) continue;
        dfs(v, u);
    }
}

int main() {
#ifdef whyqx
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &c[i][j]);

    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v), ++d[u], ++d[v];
        addE(u, v), addE(v, u);
    }

    for (int i = 1; i <= n; ++i)
        ++cnt[d[i]];

    if (cnt[1] != 2 || cnt[1] + cnt[2] != n) return puts("-1"), 0;

    long long ans = 1e18;

    int p = 0;
    for (int i = 1; i <= n; ++i)
        if (d[i] == 1) p = i;

    dfs(p, 0);

    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j) {
            if (i == j) continue;
            a[dfn[1]] = i, a[dfn[2]] = j;
            for (int k = 3; k <= n; ++k)
                a[dfn[k]] = get(a[dfn[k - 1]], a[dfn[k - 2]]);
            long long res = 0;
            for (int k = 1; k <= n; ++k)
                res += c[a[k]][k];
            if (ans > res) {
                ans = res;
                for (int k = 1; k <= n; ++k)
                    colo[k] = a[k];
            }
        }

    cout << ans << endl;
    for (int i = 1; i <= n; ++i)
        printf("%d ", colo[i]);

    return 0;
}
