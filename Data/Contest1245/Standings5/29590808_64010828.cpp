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
int main() {
	ios::sync_with_stdio(false);
	cin.exceptions(ios::badbit | ios::failbit);
	I(t);
  while(t--){
    I(n);
    vl a(256);
    cin>>a['S']>>a['R']>>a['P'];
    string s;
    cin>>s;
    vl cnt(256);
    for(auto x:s){++cnt[x];}
    string out;
    ll win = 0;
    for(auto x:s){
      char tar='E';
      if(a[x] > 0){
        tar = x;
        ++win;
      }
      else {
        for(char c:"RPS"s){
          if(a[c] > cnt[c]){
            tar = c;
            break;
          }
        }
      }
      assert(tar!='E');
      --cnt[x];
      --a[tar];
      if(tar=='S'){out+='R';}
      if(tar=='R'){out+='P';}
      if(tar=='P'){out+='S';}
    }
    if(2*win >= n){cout<<"YES"<<"\n";cout<<out<<"\n";}
    else{
      cout<<"NO"<<"\n";
    }
  }
}
