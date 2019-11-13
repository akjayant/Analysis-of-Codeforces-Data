#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

ll f[N] ;
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    string s ;
    cin >> s; 
    ll n = s.size() ;
    f[1] = 1 ;
    f[2] = 1; 
    for (int i =3 ; i < N ; i ++) {
    	f[i] = (f[i - 1] + f[i - 2]) % Mod ;
	}
	ll ans = 1 ;
	ll po = 0 ;
	for (int i = 0 ; i < n ; i ++) {
		if (s[i ] == 'm' || s[i] == 'w') return cout << 0 , 0 ;
	}
	while (po < n ) {
		if (s[po] != 'n' && s[po] != 'u') {
			po ++ ;
			continue ;
		}
		ll cnt = 0 ;
		if (s[po] == 'n') {
			while (po < n && s[po] == 'n') {
				po ++ ;
				cnt ++ ;
			}
			ans = (ans  * f[cnt + 1]) % Mod ;
			continue ;
		}
		else{
			while (po < n && s[po] == 'u') {
				po ++ ;
				cnt ++ ;
			}
			ans = (ans  * f[cnt + 1]) % Mod ;
			continue ;
		}
	}
	cout << ans ;
    
    return (0) ;
}
