#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
const int maxn = 100010;

struct edge {
  int v; edge *nxt;
  edge(int _v, edge *_nxt) : v(_v), nxt(_nxt) {}
} *fi[maxn];

std::priority_queue<std::pair<int, int> > q;
int d[maxn];

int main() {
  static int n, m, u, v, ans;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u, &v);
    d[u]++, d[v]++;
    fi[u] = new edge(v, fi[u]);
    fi[v] = new edge(u, fi[v]);
  }
  for (int i = 1; i <= n; ++i) q.push(std::make_pair(d[i], i));
  for (int i = 1; i <= n; ++i) {
    while (d[q.top().second] != q.top().first) u = q.top().second, q.pop(), q.push(std::make_pair(d[u], u));
    u = q.top().second;
    if (q.top().first == n - i) ans++;
    for (edge *j = fi[u]; j; j = j->nxt) d[j->v]--;
    q.pop();
  }
  printf("%d\n", ans - 1);
  return 0;
}
