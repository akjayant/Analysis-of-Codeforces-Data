#include <bits/stdc++.h>
using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

void pre(){


}

void solve(){


}

ll cpo=0;
vi po;vector<pii> ede;vector<pii> g[2009];
ll x[2009], y[2009], c[2009], k[2009];


ll dist(ll i, ll j){
  ll ans=0;
  if(x[i]>=x[j])ans+=x[i]-x[j];
  else ans+=x[j]-x[i];
  if(y[i]>=y[j])ans+=y[i]-y[j];
  else ans+=y[j]-y[i];
  return ans;
}
ll cost(ll i, ll j){
  return (k[i]+k[j])*(dist(i,j));
}

typedef vector<pii> Graph;

long long prim(Graph g[], vector<ll> &pred, ll n){
    pred.assign(n, -1);
    vector<bool> vis(n);
    vector<ll> prio(n, (ll)1e18);
    prio[0] = 0;
    priority_queue<pii, vector<pii> , greater<pii> > q;
    q.push(make_pair(0, 0));
    ll res = 0;

    while (!q.empty()) {
        ll d = q.top().first;
        ll u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        res += d;
        if(u==n-1) cpo++, po.pb(pred[u]);
        else if(pred[u]==n-1) cpo++, po.pb(u);
        else if(pred[u]!=-1) ede.pb(mp(pred[u],u));
        for (ll i = 0; i < (ll) g[u].size(); i++) {
            ll v = g[u][i].first;
            if (vis[v])
                continue;
            ll nprio = g[u][i].second;
            if (prio[v] > nprio) {
                prio[v] = nprio;

                pred[v] = u;
                q.push(make_pair(nprio, v));
            }
        }
    }
    return res;
}

vi pred;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
  ll n;cin>>n;
  rep(i,n)cin>>x[i]>>y[i];
  rep(i,n)cin>>c[i];
  rep(i,n)cin>>k[i];

  rep(i,n)rep(j,n)if(i!=j){
    g[i].pb(mp(j, cost(i,j)));
  }
  rep(i,n){
    g[i].pb(mp(n, c[i]));
    g[n].pb(mp(i, c[i]));
  }
  // rep(i,n+1){
  //   cout << i << ":::" << endl;
  //   trav(it, g[i])cout << "("<< it.fst << ", "<< it.snd<< ") ";cout << endl;
  // }

  cout << prim(g,pred,n+1) << endl;
  cout << cpo << endl;
  trav(it, po)cout << it+1 << ' ';cout << endl;
  cout << n-cpo << endl;
  trav(it, ede)cout << it.fst+1 << " " << it.snd+1 << endl;




	return 0;
}
