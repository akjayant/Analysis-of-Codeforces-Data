#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void dfs (int cur, int par, const vector<vector<int>>& g, vector<int>& order) {
  order.push_back(cur);
  for (int nxt : g[cur]) {
    if (nxt == par) continue;
    dfs (nxt, cur, g, order);
  }
}
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  //d
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<vector<int>> c(n, vector<int>(3));
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < n; i++) {
      cin >> c[i][j];
    }
  }
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if ((int) g[i].size() >= 3) {
      cout << -1 << '\n';
      return 0;
    }
  }
  vector<int> order;
  for (int i = 0; i < n; i++) {
    if ((int) g[i].size() == 1) {
      dfs (i, -1, g, order);
      break;
    }
  }
  vector<vector<int>> paints = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
  vector<long long> cost(6);
  for (int p = 0; p < 6; p++) {
    for (int i = 0; i < n; i++) {
      cost[p] += c[order[i]][paints[p][i % 3]];
    }
  }
  long long mi = 1LL << 60, idx = 0;
  for (int i = 0; i < 6; i++) {
    if (mi > cost[i]) {
      mi = cost[i];
      idx = i;
    }
  }
  cout << mi << '\n';
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[order[i]] = paints[idx][i % 3];
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i] + 1;
  }
  cout << '\n';
  return 0;
}