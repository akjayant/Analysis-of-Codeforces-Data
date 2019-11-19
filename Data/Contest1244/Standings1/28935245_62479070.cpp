#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

struct edge_t { int u, v, next; } G[N << 1];

ll f[N][5][5], ans;
int fr[N][5][5];
int c[5][N];
int head[N], deg[N], a[N], res[N];
int n, tot, rt, len, ansx, ansy;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

void dfs1(int u, int fa) {
    a[++len] = u;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs1(v, u);
    }
}

int main() {
    memset(f, 0x7f, sizeof(f));
    read(n);
    for(register int i = 1; i <= 3; i++) {
        for(register int j = 1; j <= n; j++) read(c[i][j]);
    }
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        ++deg[u]; ++deg[v];
        addedge(u, v);
    }
    for(register int i = 1; i <= n; i++) if(deg[i] >= 3) { print(-1, '\n'); return 0; }
    for(register int i = 1; i <= n; i++) if(deg[i] == 1) { rt = i; break; }
    dfs1(rt, 0);
    for(register int i = 1; i <= 3; i++) {
        for(register int j = 1; j <= 3; j++) {
            if(i == j) continue;
            f[2][i][j] = min(f[2][i][j], (ll)c[i][a[1]] + c[j][a[2]]);
        }
    }
    for(register int i = 3; i <= n; i++) {
        for(register int j = 1; j <= 3; j++) {
            for(register int k = 1; k <= 3; k++) {
                for(register int t = 1; t <= 3; t++) {
                    if(j == k || j == t || k == t) continue;
                    if(f[i][k][t] > f[i - 1][j][k] + c[t][a[i]]) {
                        f[i][k][t] = f[i - 1][j][k] + c[t][a[i]];
                        fr[i][k][t] = j;
                    }
                }
            }
        }
    }
    ans = f[0][0][0];
    for(register int i = 1; i <= 3; i++) for(register int j = 1; j <= 3; j++) {
        if(f[n][i][j] < ans) {
            ans = f[n][i][j];
            ansx = i; ansy = j;
        }
    }
    res[a[n - 1]] = ansx; res[a[n]] = ansy;
    for(register int i = n; i >= 3; i--) {
        int go = fr[i][ansx][ansy];
        ansy = ansx; ansx = go;
        res[a[i - 2]] = go;
    }
    print(ans, '\n');
    for(register int i = 1; i <= n; i++) print(res[i], i == n ? '\n' : ' ');
    return 0;
}