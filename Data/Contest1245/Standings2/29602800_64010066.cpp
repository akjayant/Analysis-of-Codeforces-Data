#include <cstdio>
#include <cmath>
#include <algorithm>
#define ins(u, v) fi[u] = new edge(v, fi[u]), fi[v] = new edge(u, fi[v])
const int maxn = 2010;

struct edge {
  int v; edge *nxt;
  edge(int _v, edge *_nxt) : v(_v), nxt(_nxt) {}
} *fi[maxn];

struct bian {
  int u, v; long long w;
  bool operator < (const bian &rhs) const {
    return w < rhs.w;
  }
} a[maxn * maxn];
int cnt;

int x[maxn], y[maxn], c[maxn], k[maxn];

int p[maxn];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void dfs(int u, int f) {
  for (edge *i = fi[u]; i; i = i->nxt) if (i->v != f) {
    printf("%d %d\n", u, i->v);
    dfs(i->v, u);
  }
}

int main() {
  int n; static long long ans, sum;
  scanf("%d", &n);
  for (int i = 1; i <= n + 1; ++i) p[i] = i;
  for (int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
  for (int i = 1; i <= n; ++i) scanf("%d", c + i);
  for (int i = 1; i <= n; ++i) scanf("%d", k + i);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      a[++cnt] = (bian){i, j, 1ll * (abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j])};
    }
  }
  for (int i = 1; i <= n; ++i) a[++cnt] = (bian){i, n + 1, c[i]};
  std::sort(a + 1, a + cnt + 1);
  for (int i = 1; i <= cnt; ++i) {
    int fu = find(a[i].u), fv = find(a[i].v);
    if (fu ^ fv) {
      p[fu] = fv, ans += a[i].w;
      ins(a[i].u, a[i].v);
    }
  }
  printf("%I64d\n", ans);
  for (edge *i = fi[n + 1]; i; i = i->nxt) ++sum;
  printf("%I64d\n", sum);
  for (edge *i = fi[n + 1]; i; i = i->nxt) printf("%d ", i->v);
  printf("\n%I64d\n", n - sum);
  for (edge *i = fi[n + 1]; i; i = i->nxt) dfs(i->v, n + 1);
  return 0;
}