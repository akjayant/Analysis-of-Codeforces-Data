#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

struct UnionFind {
  vector<int> par;
  vector<int> sizes;

  UnionFind(int N) : par(N), sizes(N, 1) {
    for (int i = 0; i < N; i++) par.at(i) = i;
  }

  int find(int x) {
    if (par.at(x) == x) return x;
    return par.at(x) = find(par.at(x));
  }

  void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (sizes.at(rx) < sizes.at(ry)) swap(rx, ry);
    par.at(ry) = rx;
    sizes.at(rx) += sizes.at(ry);
  }

  bool same(int x, int y) { return find(x) == find(y); }

  int size(int x) { return sizes.at(find(x)); }

  int num_of_connected_components() {
    int ret = 0;
    for (int i = 0; i < par.size(); i++) {
      if (find(i) == i) ret++;
    }
    return ret;
  }
};

int main() {
  ll n;
  cin >> n;
  vector<ll> x(n), y(n);
  REP(i, n) { cin >> x[i] >> y[i]; }
  vector<ll> c(n), k(n);
  REP(i, n) cin >> c[i];
  REP(i, n) cin >> k[i];

  // 0--n-1 上空
  // n--2n-1 下界
  //(cost, from, to)
  vector<vector<ll>> edges;
  REP(i, n) { edges.push_back({c[i], i, i + n}); }
  REP(i, n - 1) FOR(j, i + 1, n) {
    ll cost = (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
    edges.push_back({cost, i, j});
  }
  sort(ALL(edges));

  UnionFind uf(2 * n);
  FOR(i, n, 2 * n - 1) { uf.unite(i, i + 1); }
  ll sz = SZ(edges);
  ll ans = 0;
  vector<vector<bool>> to(2 * n, vector<bool>(2 * n, false));
  REP(i, sz) {
    if (uf.size(0) == 2 * n) break;
    ll cost = edges[i][0];
    ll u = edges[i][1];
    ll v = edges[i][2];
    if (uf.same(u, v)) continue;
    uf.unite(u, v);
    ans += cost;
    to[u][v] = true;
    to[v][u] = true;
  }
  cout << ans << endl;
  vector<ll> stat;
  REP(i, n) if (to[i][i + n]) { stat.push_back(i + 1); }
  cout << SZ(stat) << endl;
  REP(i, SZ(stat)) { cout << stat[i] << " \n"[i == SZ(stat) - 1]; }
  vector<P> con;
  REP(i, n) FOR(j, i + 1, n) if (to[i][j]) { con.push_back({i + 1, j + 1}); }
  cout << SZ(con) << endl;
  REP(i, SZ(con)) { cout << con[i].first << " " << con[i].second << endl; }
}