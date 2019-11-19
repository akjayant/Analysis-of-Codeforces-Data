#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

#define sz size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define per(i,a,b) for(ll i=b-1LL;i>=(a);--i)
#define clr(a, b) memset((a), (b) ,sizeof(a))
#define ctos(c) string(1,c)
#define endl "\n"
#define print(x) cout<<#x<<" = "<<x<<endl;

#define MOD 1000000007

vector<int> uf, usz;
int nc;

void init(int n){
  vector<int> uf_(n);
  vector<int> usz_(n, 1);
  uf = uf_;
  usz = usz_;
  nc = n;

  for(int i = 0; i < uf.size(); i++){
    uf[i] = i;
  }
}

int find(int a){
  return (uf[a] == a) ? a : uf[a] = find(uf[a]);
}

void union_(int a, int b){
  a = find(a);
  b = find(b);

  if(a != b){
    if(usz[a] >= usz[b]){
      swap(a, b);
    }
    uf[a] = b;
    usz[b] += usz[a];
    nc--;
  }
}

int check(int a, int b){
  return (find(a) == find(b)) ? 1 : 0;
}

int get_size(int a){
  return usz[find(a)];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector<ll> v1;
  vector<pair<ll,ll> > v2;
  ll n;
  cin>>n;
  vector<pair<ll,ll> > vp;
  rep(i,0,n){
    ll a,b;
    cin>>a>>b;
    vp.pb(mp(a,b));
  }
  vector<ll> va,vb;
  rep(i,0,n){
    ll a;
    cin>>a;
    va.pb(a);
  }
  rep(i,0,n){
    ll a;
    cin>>a;
    vb.pb(a);
  }
  vector<pair<ll,pair<ll,ll> > > v;
  rep(i,0,n){
    v.pb(mp(va[i],mp(i,n)));
  }
  rep(i,0,n){
    rep(j,0,n){
      if(i==j)continue;
      ll a = abs(vp[i].fi-vp[j].fi)+abs(vp[i].se-vp[j].se);
      v.pb(mp((vb[i]+vb[j])*a,mp(i,j)));
    }
  }
  sort(all(v));
  ll ans = 0;
  init(n+1);
  rep(i,0,v.sz){
    ll a = v[i].se.fi;
    ll b = v[i].se.se;
    ll c = v[i].fi;
    if(check(a,b)==0){
      ans += c;
      union_(a,b);
      if(b==n){
        v1.pb(a+1);
      }
      else{
        v2.pb(mp(a+1,b+1));
      }
    }
    if(nc==1)break;
  }
  cout << ans << endl;
  cout << v1.sz << endl;
  rep(i,0,v1.sz){
    cout << v1[i];
    if(i!=v1.sz-1)cout << " ";
  }
  cout << endl;
  cout << v2.sz << endl;
  rep(i,0,v2.sz){
    cout << v2[i].fi << " " << v2[i].se << endl;
  }
  return 0;
}