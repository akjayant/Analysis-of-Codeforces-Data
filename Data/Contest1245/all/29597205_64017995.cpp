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
 
const ll N = 100050;
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

vector <ll> xd;
ll fib[N];

void pre(){
	fib[0] = 1;
	fib[1] = 1;
	for(ll i = 2; i < N; i++){
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
	}
}

int main(){
    fastio;
    pre();
	string s;
	cin >> s;
	ll cons = 1;
	ll n = s.size();    
    for(ll i = 0; i < n; i++){
    	if(s[i] == 'm' or s[i] == 'w'){
    		cout << 0 << endl;
    		return 0;
    	}
    }
    for(ll i = 1; i < n; i++){
    	if(s[i] == s[i - 1]){
    		cons++;
    	}
    	else{
    		if(s[i - 1] == 'u' or s[i - 1] == 'n'){
    			xd.push_back(cons);
    		}
    		cons = 1;
    	}

    }

    if(s[n - 1] == 'u' or s[n - 1] == 'n'){
    	xd.push_back(cons);
    } 

    ll l = xd.size();
    ll ans = 1;
    for(ll i = 0; i < l; i++){
    	ans *= fib[xd[i]];
    	ans %= mod;
    }

    ans %= mod;
    if(ans < 0) ans += mod;

    cout << ans << endl;

}