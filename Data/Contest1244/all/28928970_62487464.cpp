#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef pair<double,double> pt;
const double pi = acos(-1.0);
const int mod = 1000000007;
const vi mods = {998244353,1000000007,1000000009};
const ll inf = 3e18;
const double eps = 0.0000001;
const mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define trav(a,x) for(auto&a:x)
#define all(x) begin(x),end(x)
#define sz(x) ((int)(x).size())
#define fll(xs,x,a) fill(&x,&x+sizeof(xs)/sizeof(x),a)

ll n,res=inf;
vvl cst;
unordered_map<ll,vl> g;
vl nds;
ll bestc;
ll bestd;

ll dfs(ll node,ll par,ll col,ll dir){
  ll nxc = col + (dir?1:-1);
  nxc = (nxc + 3)%3;
  ll v = cst[node][col];
  // cout<<node<<" " <<col<< v<<endl;
  trav(nx,g[node]){
    if(nx==par)continue;
    v += dfs(nx,node,nxc,dir);
  }
  return v;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.precision(13);
  cin>>n;
  cst.assign(n,vector<ll>(3));
  rep(j,0,3)rep(i,0,n)cin>>cst[i][j];
  rep(i,0,n-1){
    ll u,v;
    cin>>u>>v;
    u--;v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  rep(i,0,n){
    if(sz(g[i])>2){
      cout<<"-1\n";
      return 0;
    }
    else if (sz(g[i])==1){
      nds.push_back(i);
    }
  }
  bestc=0;
  bestd=0;
  rep(i,0,3)rep(j,0,2){
    ll nxres = dfs(nds[0],-1,i,j);
    if (nxres < res) {
      bestc=i;
      bestd=j;
      res=nxres;
    }
  }
  cout<<res<<"\n";
  vl path;
  path.resize(n);
  ll prev=-1;
  ll cur=nds[0];
  rep(i,0,n){
    path[cur]=bestc+1;
    ll nxc = bestc + (bestd?1:-1);
    nxc = (nxc + 3)%3;
    bestc=nxc;
    if(i==n-1)break;
    trav(nx,g[cur]){
      if(nx==prev)continue;
      prev=cur;
      cur=nx;
      break;
    }
  }
  rep(i,0,n)cout<<path[i]<<" \n"[i==n-1];
  return 0;
}