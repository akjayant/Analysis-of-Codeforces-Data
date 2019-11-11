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
using pr = pair<ll, char>;
using bt = bitset<64>;
#ifdef DEBUG
#include "../debug.h"
#else
#define dbg(x)
#define cerr if(false) cerr
#endif
const ll M = 1e9+7, inf = 1e18;
istream& operator>>(auto& is, auto &v) {
  for (auto &x : v) {
    cin >> x;
  }
}
int main() {
	ios::sync_with_stdio(false);
	cin.exceptions(ios::badbit | ios::failbit);
	string s;
  cin>>s;
  ll n = s.size();
  vl dp(n+1);
  dp[0] = 1;
  bool ok=1;
  fo(len,0,n){
    if(len+1 < n && s[len]==s[len+1]){
      if(s[len]=='u' || s[len]=='n'){
        (dp[len+2]+=dp[len])%=M;
      }
    }
    (dp[len+1]+=dp[len])%=M;
    if(s[len]=='m' || s[len]=='w'){
      ok=0;
      break;
    }
  }
  dbg(dp);
  if(!ok){dp[n]=0;}
  cout<<dp[n]<<"\n";
}
