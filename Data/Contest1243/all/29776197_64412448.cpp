#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

bitset<N> s, vis, v, b, all;
vector<int> g[N];
queue<int> q;

int main (void) {
  int n, m; 
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v; i <= m; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    all[i] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    ans ++;
    vis[i] = 1;
    q.push(i);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      v = all ^ vis;
      for (auto & e : g[u]) v[e] = 0;
      for (int i = v._Find_first(); i != v.size(); i = v._Find_next(i)) {
        if (vis[i]) continue;
        q.push(i);
        vis[i] = 1;
      }
    }
  }
  printf("%d\n", ans - 1);
}