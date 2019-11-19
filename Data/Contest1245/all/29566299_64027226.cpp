#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> fa;
vector<int> fb;

int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }

int gain(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) return max(fb[x], fb[y]);
  return 0;
}

vector<pair<int, int>> connections;
int unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    if (fb[x] > fb[y]) swap(x, y);
    fa[y] = x;
    return fb[y];
  }
  return 0;
}

int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  for (auto& [x, y] : a) cin >> x >> y;

  vector<int> c(n), k(n);
  for (auto& x : c) cin >> x;
  for (auto& x : k) cin >> x;

  vector<pair<ll, int>> edges;
  edges.reserve(n * (n + 1) / 2);

  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      edges.emplace_back(ll(k[i] + k[j]) * (abs(a[i].first - a[j].first) +
                                            abs(a[i].second - a[j].second)),
                         i + (j << 14));

  sort(edges.begin(), edges.end());

  fa.resize(n);
  fb.resize(n);
  for (int i = 0; i < n; ++i) {
    fa[i] = i;
    fb[i] = c[i];
  }

  ll cur = 0;
  for (int i = 0; i < n; ++i) {
    cur += c[i];
  }

  ll best = cur;
  for (auto [cost, ind] : edges) {
    int u = (ind & ((1 << 14) - 1));
    int v = (ind - u) >> 14;
    if (find(u) == find(v)) continue;
    cost -= gain(u, v);
    if (cost <= 0) {
      unite(u, v);
      best += cost;
      connections.emplace_back(u, v);
    }
  }
  cout << best << '\n';
  vector<int> nodes;
  for (int i = 0; i < n; ++i) {
    if (fa[i] == i) nodes.emplace_back(i);
  }

  cout << nodes.size() << '\n';
  for (auto x : nodes) cout << (x+1) << ' ';
  cout << '\n';
  cout << connections.size() << '\n';
  for (auto [u, v] : connections) cout << (u+1) << ' ' << (v+1) << '\n';
}