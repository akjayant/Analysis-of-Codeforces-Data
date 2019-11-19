#include <cstdio>
#include <iostream>
using namespace std;

int read();

int n;
long long f[200005][10];
int co[200005][5];
int hd[200005], nx[400005], to[400005], cnt;

int c[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2},
               {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int deg[200005];
int dp[200005];
bool cannt;
void add(int f, int t) { nx[++cnt] = hd[f], hd[f] = cnt, to[cnt] = t; }

void dfs(int u, int fa, int dep) {
    dp[u] = dep;
    for (int i = 0; i < 6; ++i) f[u][i] = co[u][c[i][dep]];
    for (int i = hd[u]; i; i = nx[i]) {
        int v = to[i];
        if (v == fa) continue;
        dfs(v, u, (dep + 1) % 3);
        for (int i = 0; i < 6; ++i) f[u][i] += f[v][i];
    }
    return;
}

int main() {
    n = read();
    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= n; ++j) co[j][i] = read();

    for (int i = 1, u, v; i < n; ++i) {
        u = read(), v = read(), add(u, v), add(v, u);
        deg[u]++, deg[v]++;
        if (deg[u] > 2 || deg[v] > 2) {
            puts("-1");
            return 0;
        }
    }
    int root;
    for (int i = 1; i <= n; ++i)
        if (deg[i] == 1) {
            root = i;
            break;
        }

    dfs(root, 0, 0);
    int res = 0;
    for (int i = 1; i < 6; ++i)
        if (f[root][i] < f[root][res]) res = i;
    printf("%I64d\n", f[root][res]);
    for (int i = 1; i <= n; ++i) printf("%d ", c[res][dp[i]] + 1);
    puts("");
    return 0;
}

int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}