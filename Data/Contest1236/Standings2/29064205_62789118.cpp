//                                      KiSmAt
#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
 
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int N = 2 * 1e5 + 10;

ll res;
ll a[N];

ll po(ll a , ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = (1LL * res * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b >>= 1;
	}
	return res;
}

inline ll add(ll x, ll y){  return  (x % mod + y % mod) % mod;}
inline ll sub(ll x, ll y){  return  (x % mod - y % mod + mod) % mod;}
inline ll mul(ll x, ll y){  x %= mod;   y %= mod;   return 1LL * x * y % mod;}

void solve(){
	ll n, m;
	cin >> n >> m;
	cout << po(sub(po(2, m), 1), n) << "\n";
}
 
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
}
// nEro