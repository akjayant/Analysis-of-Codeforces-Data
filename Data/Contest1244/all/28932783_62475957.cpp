#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll n , p , w , d ;
    cin >> n >> p >> w >> d ;
    ll res = (n * w - p ) / (w - d) ;
    if (res < 0) return cout << -1 , 0 ;
    ll cur = (p) / d ;
    for (ll i = 0 ; i <=  min({res , (ll)1000 * 100 , cur}) ; i ++) {
    	ll tmp = p - i * d ;
    	if (tmp % w == 0) {
    		return cout << tmp / w << ' ' << i  << ' ' << n - tmp / w - i , 0; 
		}
	}
	cout << -1 ;
    return (0) ;
}
