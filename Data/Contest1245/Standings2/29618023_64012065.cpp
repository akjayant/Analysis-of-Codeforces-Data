#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifdef local
  #define readfromfile(file) freopen(file, "r", stdin)
  #define debug(...) { cerr << "[" << #__VA_ARGS__ << "] = ["; \
    err(__VA_ARGS__); cerr << "]\n";}
  template<class T>
  void err(T x) { cerr << x;}
  template<class T, class...Args>
  void err(T x, Args... args){ cerr << x << ", ";err(args...);}
#else
  #define debug(...)
  #define readfromfile(...)
  #define endl '\n'
  #define cerr if(0)cout
  #define err(...)
#endif
#define fi first
#define se second
#define empb emplace_back
#define bk back
#define ppb pop_back
#define ins insert
#define clr(a, b) memset(a, b, sizeof a)
#define rep(i, n) for(int i = 0; i < n; i++)
#define ls rt << 1
#define rs rt<<1|1
#define inf 0x3f3f3f3f
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef long double ldb;
typedef complex<double> cpd;
const int N = 3e5 + 7, M = 1 << 10;
const double pi = acos(-1.0);
const int P = 7 * 17 << 23 | 1, G = 3;
const int mod = 1e9 + 7;

const int sz = 1e6 + 7;

struct Edge {
  int u, v;
  ll w;
  bool operator < (const Edge &rhs) {
    return w < rhs.w;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  readfromfile("in.txt");
  int n; cin >> n;
  vector<int> x(n + 1), y(n + 1);
  vector<Edge> E(n * (n + 1) / 2);
  for(int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<int> c(n + 1), k(n + 1);
  int tot = 0;
  for(int i = 1; i <= n; i++) {
    cin >> c[i];
    E[tot++] = {0, i, c[i]};
  }
  for(int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      E[tot++] = {i, j, (ll)(abs(x[i] - x[j]) + abs(y[i] - y[j])) * (k[i] + k[j])};
    }
  }
  sort(all(E));
  vector<int> fa(n + 1);
  iota(all(fa), 0);
  function<int(int)> Find = [&](int x) {
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
  };
  ll res = 0;
  vector<int> ans1;
  vector<pii> ans2;
  for(int i = 0; i < tot; i++) {
    int u = E[i].u, v = E[i].v;
    ll w = E[i].w;
    int fu = Find(u), fv = Find(v);
    if(fu == fv) continue;
    fa[fu] = fv;
    res += w;
    if(u == 0) {
      ans1.push_back(v);
    } else {
      ans2.push_back(pii(u, v));
    }
  }
  cout << res << endl;
  cout << ans1.size() << endl;
  for(auto &e : ans1) cout << e << ' '; cout << endl;
  sort(all(ans2));
  cout << ans2.size() << endl;
  for(auto &e : ans2) cout << e.fi << ' ' << e.se << endl;

  cerr << clock() << " ms\n";
  return 0;
}
