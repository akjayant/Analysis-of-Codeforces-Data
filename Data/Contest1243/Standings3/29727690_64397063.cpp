// TY Swistakk 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
typedef long double ld;
 
const ll N = 200050;
const ll N1 = 100500;
const ll mod = 1000000007;
 
using namespace std;
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << endl;}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1<<" | ";
  __f(comma+1, args...);}
#else
#define trace(...)
#endif

vector <ll >xd;

int main(){

	fastio;
  	ll n;
  	cin >> n;
  	ll ans = n;

  	for(ll i = 2; i * i <= n; i++){
  		if(n % i == 0) {xd.push_back(i); xd.push_back(n / i);}
  	}
  	ll l = xd.size();
  	for(ll i = 0; i < l; i++){
  		
  		ans = __gcd(ans, xd[i]);
  	}
  	cout << ans << endl;

  	return 0;
}

