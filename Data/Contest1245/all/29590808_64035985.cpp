#include <bits/stdc++.h>
#define fo(i, a, b) for (ll i = a; i < ll(b); i++)
#define fr(i, a, b) for (ll i = b - 1; i >= ll(a); i--)
#define al(x) begin(x), end(x)
#define ral(x) rbegin(x), rend(x)
#define I(x) ll x; cin >> x;
#define this (*this)
#define ar array
#define vc vector
#define pb push_back
#define rs resize
#define is insert
#define vl vc<ll>
#define popcnt __builtin_popcountll
#define sp <<" "<<
#define endl "\n"
using namespace std;
using namespace std::placeholders;
using ll = long long;
using ld = long double;
using pa = array<ll, 2>;
using ve = ar<ll,3000>;
using mt = ar<ve,3000>;
using pr = pair<ll, ll>;
using bt = bitset<64>;
#ifdef DEBUG
#include "../debug.h"
#else
#define dbg(x)
#define cerr if(false) cerr
#endif
const ll M = 998244353, inf = 1e18;
istream& operator>>(auto& is, auto &v) {
  for (auto &x : v) {
    cin >> x;
  }
  return is;
}
vl p;
ll fd(ll x){
  //cerr<<x<<endl;
  return p[x]==x?x:(p[x] = fd(p[x]));
}
ll mg(ll x, ll y){
  if(fd(x) != fd(y)){
    p[fd(x)] = fd(y);
  }
}
int main() {
	ios::sync_with_stdio(false);
	cin.exceptions(ios::badbit | ios::failbit);  
  I(n);
  p.resize(n+1);
  fo(i,0,p.size()){
    p[i] = i;
  }
  vl x(n),y(n),c(n),k(n);
  fo(i,0,n){
    cin>>x[i];
    cin>>y[i];
  }
  cin>>c>>k;
  vc<pair<ll, pr>> es;
  fo(i,0,n){
    es.pb({c[i], {i, n}});
    es.pb({c[i], {n, i}});
    fo(j,0,n){
      if(i != j){
        es.pb({(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])), {i, j}});
      }
    }
  }
  sort(al(es));
  vc<pr> ans;
  ll cost = 0;
  ll ecnt = 0;
  for(auto [d,paa]:es){
    auto [i,j] = paa;
    dbg(i);dbg(j);
    if(fd(i) != fd(j)){
      dbg(i);dbg(j);
      //mg(i,j);
      if(fd(i) != fd(j)){
        p[fd(i)] = fd(j);
      } 
      /*ll fi = fd(i);
      ll fj = fd(j);
      dbg(fi);dbg(fj);
      p[fi] = fj;*/
      //mg(i,j);
      ans.pb({i,j});
      if(i!=n&&j!=n){++ecnt;}
      cost+=d;
      dbg(i);dbg(j);
    }
  }
  dbg(ans);
  vl pw(n);
  ll tot =0;
  for(auto paa:ans){
    auto [i,j] = paa;
    if(i == n){
      pw[j] = 1;
    }
    if(j == n){
      pw[i] = 1;
      ++tot;
    }
  }
  cout<<cost<<"\n";
  cout<<tot<<"\n";
  fo(i,0,n){
    if(pw[i]){cout<<1+i<<" ";}
  }
  cout<<"\n";
  cout<<ecnt<<"\n";
  for(auto paa:ans){
    auto [i,j] = paa;
    if(i != n && j != n){
      cout<<1+i<<" "<<1+j<<"\n";
    }
  }
}
