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
void no() {
  cout << -1 << endl;
  exit(0);
}

ll n, s, t;
vector<vector<ll>> c, to, cost;
vector<ll> topo;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
void dfs(ll cv, ll par) {
  topo.push_back(cv);
  FOREACH(nv, to[cv]) {
    if (nv == par) continue;
    dfs(nv, cv);
  }
}

int main() {
  ll n;
  cin >> n;
  c = vector<vector<ll>>(3, vector<ll>(n));
  REP(i, 3) REP(j, n) { cin >> c[i][j]; }
  to = vector<vector<ll>>(n);
  REP(i, n - 1) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    to[u].push_back(v);
    to[v].push_back(u);
  }
  s = -1;
  REP(i, n) {
    if (SZ(to[i]) > 2) no();
    if (SZ(to[i]) == 1) s = i;
  }
  ll ans = 1e18;
  dfs(s, -1);
  // 1,2の色を固定
  vector<ll> d = {0, 1, 2};
  vector<ll> ansd;
  do {
    ll cost = 0;
    REP(i, n) {
      ll j = topo[i];
      cost += c[d[i % 3]][j];
    }
    if (cost < ans) {
      ans = cost;
      ansd = d;
    }
  } while (next_permutation(ALL(d)));
  cout << ans << endl;
  vector<ll> color(n);
  REP(i, n) {
    ll j = topo[i];
    color[j] = ansd[i % 3];
  }
  REP(i, n) { cout << color[i] + 1 << " \n"[i == n - 1]; }
}