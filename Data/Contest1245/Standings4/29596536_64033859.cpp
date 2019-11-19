#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
const int n_max=2019;
ll c[n_max];

struct UnionFind {
  vector< int > data;
  vector< ll > cost;
  
  UnionFind(int sz) {
    data.assign(sz, -1);
    rep(i,sz){
      cost.pb(c[i]);
    }
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    cost[x] = min(cost[x],cost[y]);
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }

  int cal_cost(int k){
    return cost[find(k)];
  }
};

vector<pair<int,int> > ans;
template< typename T >
T kruskal(Edges< T > &edges, int V) {
  sort(begin(edges), end(edges), [](const edge< T > &a, const edge< T > &b) {
    return (a.cost < b.cost);
  });
  UnionFind tree(V);
  T ret = 0;
  ll tot_cost=0;
  for(auto &e : edges) {
    if(tree.find(e.src) ==  tree.find(e.to)) continue;
    ll cut_cost = max(tree.cal_cost(e.src), tree.cal_cost(e.to));
    ll con_cost = e.cost;
    if(cut_cost >= con_cost){      
      tree.unite(e.src, e.to);
      ans.pb(mp(e.src, e.to));
      ret += e.cost;
      tot_cost += e.cost;
    }
  }
  int v=0;
  vector<int> tcost;
  rep(i,V){
    if(tree.find(i)==i){
      v++;
    }
    if(tree.cal_cost(i) == c[i]){
      tcost.pb(i+1);
      tot_cost+=c[i];
    }
  }
  cout << tot_cost << endl;
  cout << v << endl;
  rep(j,v) cout << tcost[j] << " " ;
  cout << "" << endl;

  cout << V - v << endl;
  rep(j,ans.size()){
    cout << ans[j].first+1 << " " << ans[j].second+1 << endl;
  }
  
  return (ret);
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  Edges<ll> edges;
  ll n;
  cin >> n;
  pair<ll,ll> cor[n];
  ll x[n],y[n];
  rep(i,n){
    cin >> x[i] >> y[i];
    cor[i]=mp(x[i],y[i]);
  }
  ll k[n];
  rep(i,n) cin >> c[i];
  rep(i,n) cin >> k[i];

  rep(i,n){
    rep(j,n){
      if(i!=j){
	edges.emplace_back(i,j,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])) );
      }
    }
  }
  ll ans = kruskal(edges,n);
  return 0;
    

}
