#include <bits/stdc++.h>

using namespace std;

struct edge {
  int u, v;
  long long w;

  edge(int x = 0, int y = 0, long long z = 0) : u(x), v(y), w(z) {}

  const bool operator<(const edge& a) const {
    return w < a.w;
  }
};

class dsu {
  vector<int> p;
public:
  dsu(int n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  int get(int v) {
    return (v == p[v] ? v : p[v] = get(p[v]));
  }

  void unite(int u, int v) {
    p[get(u)] = get(v);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> x(n), y(n), c(n), k(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  dsu d(n + 1);
  vector<edge> kek;
  for (int i = 0; i < n; ++i) {
    kek.emplace_back(n, i, c[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      kek.emplace_back(i, j, 1ll * (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j])));
    }
  }
  sort(kek.begin(), kek.end());
  vector<int> ps;
  long long ans = 0;
  vector<pair<int, int>> rofl;
  for (int i = 0; i < kek.size(); ++i) {
    int u = kek[i].u, v = kek[i].v;
    long long w = kek[i].w;
    if (d.get(u) != d.get(v)) {
      d.unite(u, v);
      if (u == n) {
        ps.push_back(v + 1);
      } else {
        rofl.emplace_back(u + 1, v + 1);
      }
      ans += w;
    }
  }
  cout << ans << '\n' << ps.size() << '\n';
  for (int xx : ps) {
    cout << xx << ' ';
  }
  cout << '\n' << rofl.size() << '\n';
  for (auto [u, v] : rofl) {
    cout << u << ' ' << v << '\n';
  }

  return 0;
}