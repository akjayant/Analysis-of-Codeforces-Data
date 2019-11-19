#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, root, a[3][N], c[N], col[N], deg[N];
long long now, ans = 1e18;
std::vector<int> e[N];

bool check() {
    for (int i = 0; i < n; i++) {
        if (deg[i] >= 3) { return true; }
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) { root = i; }
    }
    return false;
}

void dfs(int u, int fa, int x, int y, int z) {
    now += a[x][u]; c[u] = x;
    for (auto v : e[u]) {
        if (v != fa) {
            dfs(v, u, y, z, x);
        }
    }
}

int main() {
    n = read();
    for (int x = 0; x < 3; x++) {
        for (int i = 0; i < n; i++) { a[x][i] = read(); }
    }
    for (int i = 1; i < n; i++) {
        int u = read(), v = read(); u--; v--;
        e[u].push_back(v); e[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    if (check()) { printf("-1"); return 0; }
    now = 0; dfs(root, n, 0, 1, 2);
    if (ans > now) {
        ans = now;
        for (int i = 0; i < n; i++) { col[i] = c[i]; }
    }
    now = 0; dfs(root, n, 0, 2, 1);
    if (ans > now) {
        ans = now;
        for (int i = 0; i < n; i++) { col[i] = c[i]; }
    }
    now = 0; dfs(root, n, 1, 0, 2);
    if (ans > now) {
        ans = now;
        for (int i = 0; i < n; i++) { col[i] = c[i]; }
    }
    now = 0; dfs(root, n, 1, 2, 0);
    if (ans > now) {
        ans = now;
        for (int i = 0; i < n; i++) { col[i] = c[i]; }
    }
    now = 0; dfs(root, n, 2, 0, 1);
    if (ans > now) {
        ans = now;
        for (int i = 0; i < n; i++) { col[i] = c[i]; }
    }
    now = 0; dfs(root, n, 2, 1, 0);
    if (ans > now) {
        ans = now;
        for (int i = 0; i < n; i++) { col[i] = c[i]; }
    }
    printf("%I64d\n", ans);
    for (int i = 0; i < n; i++) { printf("%d ", col[i] + 1); }
    return 0;
}