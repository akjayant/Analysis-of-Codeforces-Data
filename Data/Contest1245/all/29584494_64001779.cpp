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

int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll q; 
    cin >> q ;
    while (q --) {
    	ll n ; 
    	cin >> n; 
    	ll a , b , c ;
    	cin >> a >> b >> c ;
    	string t ;
    	cin >> t ;
    	string ans = "" ;
    	ll cnt = 0 ;
    	for (int i = 0 ; i < n ; i ++) {
    		if (t[i] == 'S') {
    			if (!a) {
    				ans += "0" ;
    				continue ;
				}
    			a -- ;
    			ans += "R" ;
    			cnt ++ ;
			}
			if (t[i] == 'R') {
				if (!b) {
					ans += "0" ;
					continue ;
				}
				b -- ;
				cnt ++ ;
				ans += "P" ;
			}
			if (t[i] == 'P') {
				if (!c) {
					ans += "0" ;
					continue ;
				}
				c -- ;
				cnt ++ ;
				ans += "S" ;
			}
		}
		if (cnt * 2 < n) cout << "NO\n" ;
		else {
			cout << "YES\n" ;
			for (int i =  0 ; i < n ; i ++) {
				if (!a) continue ;
				if (ans[i] != '0') continue ;
				ans[i] = 'R' ;
				a -- ;
			}
				for (int i =  0 ; i < n ; i ++) {
				if (!b) continue ;
				if (ans[i] != '0') continue ;
				ans[i] = 'P' ;
				b -- ;
			}
				for (int i =  0 ; i < n ; i ++) {
				if (!c) continue ;
				if (ans[i] != '0') continue ;
				ans[i] = 'S' ;
				c -- ;
			}
			
			cout << ans << '\n' ;
		}
	}
    
    return (0) ;
}
