#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 11;
set<int> g[N];
int dsu[N], p[N];

void init(int n) {  
  for(int i = 0; i < n; ++i) {
    dsu[i] = i;
    p[i] = 1;
  }
}

int getu(int u) {
  if(dsu[u] == u) return u;
  return dsu[u] = getu(dsu[u]);
}

void un(int u, int v) {
  u = getu(u);
  v = getu(v);

  if(p[u] > p[v]) {
    swap(u, v);
  }

  dsu[u] = v;
  p[v] += p[u];

  vector<int> res;
  for(int i : g[u]) {
    if(g[v].count(i)) {
      res.push_back(i);
    }
    g[i].erase(u);
  }
  for(int i : g[v]) {
    g[i].erase(v);
  }
  g[v].clear();
  g[u].clear();
  for(int i : res) {
    g[v].insert(i);
    g[i].insert(v);
  }
}

void solve() {
  init(N);
  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].insert(v);
    g[v].insert(u);
  }

  set<int> p;
  for(int i = 0; i < n; ++i) {
    p.insert(i);
  }
  int res = 0;
  while(p.size() > 1) {
    int u = *p.begin();
    p.erase(p.begin());
    if(g[u].size() == p.size()) {
      p.erase(*g[u].begin());
      un(u, *g[u].begin());
      res++;
      p.insert(getu(u));
    } else {
      for(int v : p) {
        if(g[u].count(v) == 0) {
          p.erase(v);
          un(u, v);
          p.insert(getu(u));
          break;
        }
      }
    }
  }
  cout << res << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
}