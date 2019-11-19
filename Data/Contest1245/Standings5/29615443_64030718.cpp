#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 5;
const int P = 1e9 + 7;
void solve();
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
}
//
struct node {
  ll x, y;
} a[N];
struct edge {
  ll u, v, w;
  bool operator < (const edge &b) const {
    return w < b.w;
  }
} b[N * N];
ll c[N], k[N], tot, par[N * N];
ll v1[N], v2[N * 2], c1, c2;
int get(int x) {
  if (par[x] == x) return x;
  return par[x] = get(par[x]);
}
bool add(int x, int y) {
  x = get(x), y = get(y);
  if (x == y) return 1;
  par[y] = x;
  return 0;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  for (int i = 1; i <= n; i++) {
    b[tot++] = {n + 1, i, c[i]};
    for (int j = i + 1; j <= n; j++) {
      ll w = (ll)(k[i] + k[j]) * (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y));
      b[tot++] = {i, j, w};
    }
  }
  for (int i = 1; i <= n + 1; i++) {
    par[i] = i;
  }
  sort(b, b + tot);
  ll ans = 0;
  for (int i = 0; i < tot; i++) {
    if (!add(b[i].u, b[i].v)) {
      ans += b[i].w;
      if (b[i].u == n + 1) v1[c1++] = b[i].v;
      else v2[c2++] = b[i].u, v2[c2++] = b[i].v;
    }
  }
  cout << ans << '\n';
  cout << c1 << '\n';
  for (int i = 0; i < c1; i++) {
    if (i) cout << ' ';
    cout << v1[i] << ' ';
  }
  if (c1) cout << '\n';
  cout << (c2 / 2) << '\n';
  for (int i = 0; i < c2; i += 2) {
    cout << v2[i] << ' ' << v2[i+1] << '\n';
  }
}
