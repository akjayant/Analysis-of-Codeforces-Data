#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<ll, ll>
#define mp make_pair
#define pb push_back
#define vi vector<ll>
#define pd pair<double, double>
#define vp vector<pi>
#define f(i, n) for(int i = 0; i < n; i++)
#define fo(i, a, n) for(int i = a; i < n; i++)
#define mod (1000*1000*1000+7)
#define sz(x) int((x).size())
#define all(x) x.begin(),x.end()
#define DBG(v) cerr << #v << " = " << (v) << endl;
ll INF = (1ll<<61);

#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define SZ(x) int((x).size())
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

using namespace std;

vp *g;

vector<pi> mst;
ll prim2 (int n, vector<pi> *adj) {
  ll cost = 0; mst.clear(); vector<bool> done(n+1,0);
  priority_queue<pair<ll,pi> > q;
  q.push(mp(0,mp(-1,0))); // minus cost, from, to
  while (!q.empty()) {
  ll v = q.top().se.se, d = -q.top().fi, from = q.top().se.fi;
  q.pop(); if (done[v]) continue; done[v] = 1; cost += d;
  if (from != -1) mst.pb(mp(from,v));
  FOREACH(it,adj[v]) if (!done[it->fi]) q.push(mp(-it->se,mp(v,it->fi)));
  }
  return cost;
}


int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    g = new vp[n+1];
    vp v(n); vi c(n+1), k(n+1);
    f(i, n) cin >> v[i].first >> v[i].second;
    f(i, n) cin >> c[i+1];
    f(i, n) cin >> k[i+1];
    f(i, n){
      fo(j, i+1, n){
        ll x = abs(v[i].first - v[j].first);
        ll y = abs(v[i].second - v[j].second);
        g[i+1].pb(mp( j + 1,(k[i+1] + k[j+1]) * (x + y)));
        g[j+1].pb(mp( i+1,  (k[j+1] + k[i+1]) * (x + y)));
      }
    }
    f(i, n) g[0].pb(mp(i+1, c[i+1]));
    ll res = prim2(n+1, g);
    cout << res << endl;
    vi pwr; vp cc;
    f(i, sz(mst)){
      if(mst[i].first == 0) pwr.pb(mst[i].second);
      else cc.pb(mst[i]);
    }
    cout << sz(pwr) << endl;
    f(i, sz(pwr)) cout << pwr[i] << " ";
    cout << endl;
    cout << sz(cc) << endl;
    f(i, sz(cc)) cout << cc[i].first << " " << cc[i].second << '\n';
    return 0;
}
