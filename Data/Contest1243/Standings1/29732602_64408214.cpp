#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fst first
#define snd second
#define PI (acos(-1))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

#define MAXN 1123456
#define MOD 1000000007

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;

struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool same_set(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;

  set<pii> edges;
  rep(i,0,m) {
    int u, v;
    cin >> u >> v;
    edges.insert({u,v});
    edges.insert({v,u});
  }

  UF uf(n+1);
  vi unreached;
  rep(i,1,n+1) unreached.pb(i);

  while (not unreached.empty()) {
    queue<int> q;
    q.push(unreached.back());
    unreached.pop_back();
    while (not q.empty()) {
      ll u = q.front(); q.pop();
      vi still;
      trav(v, unreached) {
        if (edges.find(make_pair(u,v)) != edges.end() or edges.find(make_pair(v,u)) != edges.end()) {
          still.pb(v);
        } else {
          uf.join(u, v);
          q.push(v);
        }
      }
      unreached = still;
    }
  }

  ll ans = 0;
  trav(e, edges) {
    int u, v;
    tie(u, v) = e;
    if (not uf.same_set(u,v)) {
      ++ans;
      uf.join(u,v);
    }
  }

  cout<<ans<<endl;

}
