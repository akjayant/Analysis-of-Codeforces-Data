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
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll t ;
    cin >> t ;
    while (t --){
    	ll a , b , c , d , k ;
    	cin >> a >> b >> c >> d >> k ;
    	ll ans1 = (a + c - 1) / c , ans2= (b + d - 1) / d ;
    	if (ans1 + ans2 <= k) cout << ans1 << ' ' << ans2 << '\n' ;
    	else cout << "-1\n" ;
	}
	    
    return (0) ;
}
