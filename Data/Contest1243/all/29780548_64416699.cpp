#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
const int maxn = 100010;
const int maxm = 16;

struct node {
  int x, y, z;
} ans[maxm + 10];

struct edge {
  int v; edge *nxt;
  edge(int _v, edge *_nxt) : v(_v), nxt(_nxt) {}
} *fi[maxn];

std::map<long long, int> map;
std::vector<node> vec[1 << maxm];
long long g[maxm + 10][maxn], cnt[maxm + 10];
int f[1 << maxm];

void dfs(int u);

int main() {
  int n; static long long ans;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", g[i]);
    for (int j = 1; j <= g[i][0]; ++j) {
      scanf("%I64d", g[i] + j);
      map[g[i][j]] = i, ans += g[i][j], cnt[i] += g[i][j];
    }
  }
  if (ans % n) return puts("No"), 0;
  ans /= n, f[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= g[i][0]; ++j) {
      int flag = 0, t = ans - (cnt[i] - g[i][j]);
      if (!map.count(t) || (t != g[i][j] && map[t] == i)) continue;
      int sta = 1 << i;
      for (int k = map[t]; k != i; k = map[t]) {
        t += ans - cnt[k];
        if (!map.count(t) || ((sta >> k) & 1)) { flag = 1; break; }
        sta |= (1 << k);
      }
      if (t == g[i][j] && !flag) {
        t = ans - (cnt[i] - g[i][j]), vec[sta].push_back((node){map[t], t, i});
        for (int k = map[t]; k != i; k = map[t]) t += ans - cnt[k], vec[sta].push_back((node){map[t], t, k});
        f[sta] = 1;
      }
    }
  }
  for (int s = 0; s < (1 << n); ++s) if (!f[s]) {
    for (int u = s; u; u = (u - 1) & s) {
      if (f[u] && f[s ^ u]) {
        fi[s] = new edge(u, fi[s]);
        fi[s] = new edge(s ^ u, fi[s]);
        f[s] = 1; break;
      }
    }
  }
  if (!f[(1 << n) - 1]) return puts("No"), 0;
  dfs((1 << n) - 1);
  puts("Yes");
  for (int i = 0; i < n; ++i) printf("%d %d\n", ::ans[i].y, ::ans[i].z + 1);
  return 0;
}

void dfs(int u) {
  for (auto i : vec[u]) ans[i.x] = i;
  for (edge *i = fi[u]; i; i = i->nxt) dfs(i->v);
}
