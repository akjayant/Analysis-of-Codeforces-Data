#include <bits/stdc++.h>
// #include "debug.hpp"
using namespace std;

#define pb push_back
#define SZ(s) ((int)s.size())
#define all(vec) vec.begin(), vec.end()

using ll = long long;
template <class T> using V = vector<T>;

template <class T, class U>
bool chkmin(T& x, U y) {
  return (x > y) ? (x = y, true) : false;
}
template <class T, class U>
bool chkmax(T& x, U y) {
  return (x < y) ? (x = y, true) : false;
}
int add(int x, int y, int mod) {
  x += y;
  return (x >= mod) ? (x - mod) : x;
}
int sub(int x, int y, int mod) {
  x -= y;
  return (x < 0) ? (x + mod) : x;
}
int mul(int x, int y, int mod) {
  return (ll)x * y % mod;
}
int qpow(int a, int t, int mod) {
  int b = 1;
  for (; t > 0; t >>= 1, a = mul(a, a, mod)) {
    if (t & 1) b = mul(b, a, mod);
  }
  return b;
}

V<int> G[101010];
ll c[101010][3], dp[101010][3][3];
int color[101010];

int get(int x, int y) {
  for (int i = 0; i < 3; i++) {
    if (i != x && i != y) return i;
  }
  assert(false);
  return -1;
}

ll dfs(int u, int f, int x, int y) {
  color[u] = x;
  ll ret = c[u][x];
  for (auto& v : G[u]) {
    if (v != f) ret += dfs(v, u, y, get(x, y));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n; cin >> n;
  for (int j = 0; j < 3; j++) {
    for (int i = 1; i <= n; i++) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    G[u].push_back(v), G[v].push_back(u);
  }
  int rt = -1;
  for (int i = 1; i <= n; i++) {
    if (SZ(G[i]) > 2) {
      cout << "-1\n";
      return 0;
    }
    if (SZ(G[i]) == 1) {
      rt = i;
    }
  }
  if (rt == -1) {
    cout << "-1\n";
    return 0;
  }
  ll ans = 1ll << 62;
  int tx = -1, ty = -1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == j) continue;
      ll tmp = dfs(rt, -1, i, j);
      if (tmp < ans) ans = tmp, tx = i, ty = j;
    }
  }
  dfs(rt, -1, tx, ty);
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) {
    cout << color[i] + 1 << " \n"[i == n];
  }
}