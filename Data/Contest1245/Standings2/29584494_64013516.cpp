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

vector<pair<ll , pll> > E ;
ll  n , x[N] , y[N] , c[N] , k[N] , p[N];
ll get(ll i , ll j) {
	ll res =  abs(x[i] - x[j]) + abs(y[i ] - y[j]) ;
	res  *= (k[i] + k[j]) ;
	return res ;
}
ll Get(ll v) {
	if (p[v] == v) return v ;
	return p[v] = Get(p[v]) ;
}
bool Add(ll v , ll u) {
	v = Get(v) ;
	u = Get(u) ;
	if (v == u) return 0 ;
	if (rand() % 2) swap(v , u) ;
	p[v] = u ;
	return 1; 
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> n ;
    for (int i = 1; i <= n ; i ++) cin >> x[i] >> y[i] ;
    for (int i = 0 ; i < N ; i ++) p[i] = i ;
    for (int i = 1 ; i <= n ; i ++) cin >> c[i] ;
    for (int i = 1;  i <= n ; i ++) cin >> k[i] ;
    for (int i = 1;  i <= n ; i ++) {
    	for (int j = i + 1 ; j <= n ; j ++) {
    		E.pb({get(i , j) , { i , j}}) ;
		}
	}
	for (int i = 1;  i <= n ; i ++) E.pb({c[i] , {0 , i}}) ;
	sort(all(E)) ;
	vector<ll> sing ;
	vector<pll> edg ;
	ll ans = 0 ;
	for (int i = 0 ; i < E.size() ; i ++) {
		ll w = E[i].F , v = E[i].S.F , u = E[i].S.S ;
		if (Add(v , u)) {
			if (min(v , u) == 0) {
				sing.pb(max(v , u)) ;
			}
			else edg.pb({v , u}) ;
			ans += w ;
		}
	}
	cout << ans << '\n' ;
	cout << sing.size() << '\n' ;
	for (auto u : sing) cout << u << ' ' ;
	cout << '\n' ;
	cout << edg.size() << '\n' ;
	for (auto u : edg ) cout << u.F << ' ' << u.S << '\n';
    return (0) ;
}
