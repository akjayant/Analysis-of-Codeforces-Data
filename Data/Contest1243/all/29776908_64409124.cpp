#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=double;
using pll=pair<ll,ll>;
using vll=vector<ll>;
using vpll=vector<pll>;
using vvll=vector<vll>;
#define FOR(i,a,b) for(ll i=a;i<(ll)b;++i)
#define ROF(i,a,b) for(ll i=a;i>=(ll)b;--i)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define aa first
#define bb second
#define PB push_back
#define EQ(a,b) (fabs(a-b)<=(fabs(a+b)*EPS))
#define mp make_pair
#define INF (1ll << 40)

set<ll> nv;
map<ll,set<ll>> e;
void dfs(ll v) {
  nv.erase(v);
  for (auto i = nv.begin(); i != nv.end();) {
    if (!e[v].count(*i) && nv.count(*i))
      dfs(*i);
    i = nv.upper_bound(*i);
    if (i == nv.end()) return;
  }
}

int main(){
  ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
  ll n;
  cin >> n;
  ll m;
  cin >> m;
  F(n) nv.insert(i);
  F(m) {
    ll a, b;
    cin >> a >> b;
    a --; b --;
    e[a].insert(b);
    e[b].insert(a);
  }

  ll res = 0;
  F(n) {
    if (nv.count(i)) {
      res ++;
      dfs(i);
    }
  }
  cout << res-1 << endl;

  return 0;
}
