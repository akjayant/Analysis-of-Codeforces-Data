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
    ll t; 
    cin >> t ;
    while (t --) {
    	ll n ;
    	cin >> n ;
    	string s ;
    	cin >> s; 
    	ll ans = n ;
    	for (ll i = 0 ; i < s.size() ; i ++) {
    		if (s[i] == '1') {
    			ans = max(ans , 2 * (max(i + 1, n - i))) ;
			}
		}
		cout << ans << '\n' ;
	}
    
    return (0) ;
}
