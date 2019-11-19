#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#ifdef ConanYu
#include "local.hpp"
#else
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

const int N = 1e5 + 10;
int deg[N], h[N], tot;

struct edge {
  int v, nxt;
} G[N << 1];

void addedge(int u, int v) {
  G[tot] = {v, h[u]}; h[u] = tot++;
  G[tot] = {u, h[v]}; h[v] = tot++;
  deg[u]++, deg[v]++;
}
const int p[6][3] = {
  {0, 1, 2},
  {0, 2, 1},
  {1, 0, 2},
  {1, 2, 0},
  {2, 0, 1},
  {2, 1, 0}
};
int col[3][N];
int rc[N];
ll res;
void dfs(int x, int fa, int id, int m) {
  res += col[p[m][id]][x];
  rc[x] = p[m][id];
  for(int i = h[x]; ~i; i = G[i].nxt) {
    if(G[i].v != fa) {
      dfs(G[i].v, x, (id + 1) % 3, m);
    }
  }
}

void Main() {
  int n; cin >> n;
  memset(h, 0xff, sizeof(*h) * n);
  tot = 0;
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < n; j++) {
      cin >> col[i][j];
    }
  }
  for(int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    addedge(u, v);
  }
  int id = -1;
  for(int i = 0; i < n; i++) {
    if(deg[i] == 1) id = i;
    else if(deg[i] > 2) {
      cout << "-1\n";
      return;
    }
  }
  ll ans = LLONG_MAX;
  int aim = -1;
  for(int k = 0; k < 6; k++) {
    res = 0;
    dfs(id, -1, 0, k);
    if(ans > res) {
      ans = res;
      aim = k;
    }
  }
  cout << ans << "\n";
  dfs(id, -1, 0, aim);
  for(int i = 0; i < n; i++) {
    cout << (rc[i] + 1) << " \n"[i == n - 1];
  }
}
