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

ll a[N] ;
ll c[2][2] ;
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll t ;
    cin >> t ;
    while (t --) {
    	ll n ;
    	cin >> n ;
    	for (int i = 0 ; i < 2 ; i ++) for (int j = 0 ; j < 2 ; j ++) c[i][j] = 0 ;
    	while (n --) {
    		ll x ;
    		cin >> x ;
    		c[0][x & 1] ++ ;
		}
		ll m ;
		cin >> m ;
		while (m --) {
			ll x ;
			cin >> x ;
			c[1][x & 1] ++ ;
		}
		cout << c[1][1] * c[0][1] + c[0][0] * c[1][0] << '\n' ;
	}
	
	    
    return (0) ;
}
