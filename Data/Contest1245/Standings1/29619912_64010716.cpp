#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll x[2010];
ll y[2010];
ll c[2010];
ll k[2010];

vector<tuple<ll, ll, ll, bool>> edges;

ll parent[2010];

ll find(ll a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

vector<ll> stations;
vector<pair<ll, ll>> conns;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  ll n;
  cin>>n;
  for (ll i=1; i<=n; ++i) {
    cin>>x[i]>>y[i];
  }
  for (ll i=1; i<=n; ++i) cin>>c[i];
  for (ll i=1; i<=n; ++i) cin>>k[i];
  for (ll i=1; i<=n; ++i) {
    edges.push_back({c[i], 0, i, true});
    for (ll j=i+1; j<=n; ++j) {
      edges.push_back( {(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])), i, j, false});
    }
  }
  for (ll i=0; i<=n; ++i) parent[i]=i;
  sort(edges.begin(), edges.end());
  ll used=0;
  ll cost=0;
  for (auto e:edges) {
    ll u=get<1>(e);
    ll v=get<2>(e);
    ll C = get<0>(e);
    if (find(u)==find(v)) continue;
    cost+=C;
    parent[find(u)] = find(v);
    if (get<3>(e)) {
      stations.push_back(v);
    } else {
      conns.push_back({u, v});
    }
  }
  cout<<cost<<endl;
  cout<<stations.size()<<endl;
  for (auto a:stations)cout<<a<<" ";
  cout<<endl;
  cout<<conns.size()<<endl;
  for (auto a:conns)cout<<a.first<<" "<<a.second<<endl;
  

}