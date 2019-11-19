#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e3 + 5;

int n, x[N], y[N], c[N], d[N], from[N];
long long ans, dis[N], w[N][N];
bool used[N];

std::vector<int> f;
std::vector<std::pair<int, int>> g;

void prim() {
    int s = 0; used[s] = true;
    for (int u = 0; u < n; u++) {
        if (!used[u]) { from[u] = s; dis[u] = w[s][u]; }
    }
    for (int i = 1; i < n; i++) {
        s = -1;
        for (int u = 0; u < n; u++) {
            if (!used[u]) {
                if (s == -1 || dis[s] > dis[u]) { s = u; }
            }
        }
        if (s == -1) { return; }
        ans += w[from[s]][s]; used[s] = true;
        if (from[s] == 0) {
            f.push_back(s);
        } else {
            g.push_back({from[s], s});
        }
        for (int u = 0; u < n; u++) {
            if (!used[u]) {
                if (dis[u] > w[s][u]) {
                    dis[u] = w[s][u]; from[u] = s;
                }
            }
        }
    }
}

int main() {
    n = read(); n++;
    for (int i = 1; i < n; i++) { x[i] = read(); y[i] = read(); }
    for (int i = 1; i < n; i++) { c[i] = read(); }
    for (int i = 1; i < n; i++) { d[i] = read(); }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long tmp;
            if (i == 0) {
                tmp = c[j];
            } else {
                tmp = 1ll * (d[i] + d[j]) * (std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]));
            }
            w[i][j] = w[j][i] = tmp;
        }
    }
    prim();
    printf("%I64d\n", ans);
    printf("%d\n", f.size());
    for (auto u : f) { printf("%d ", u); }
    printf("\n");
    printf("%d\n", g.size());
    for (auto i : g) { printf("%d %d\n", i.first, i.second); }
    return 0;
}