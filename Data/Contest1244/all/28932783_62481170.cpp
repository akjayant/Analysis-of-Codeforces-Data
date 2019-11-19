#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 4e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

ll n ;
vector<ll> G[N] ;
ll cnt[N] ;
vector<ll> V ;
ll M[N] ;
ll cost[10][N] ;
vector<ll> cur = {0 , 1 , 2} ;
ll k[N]  ,ans = 1e18;
ll f() {
	ll res = 0 ;
	for (int i = 0 ; i < V.size() ; i ++) {
		res += cost[cur[i % 3]][V[i]] ;
	}
	if (res < ans) {
		ans = res ;
		for (int i = 0 ; i < V.size() ; i ++) {
			k[V[i]] = cur[i % 3] ;
		}
	}
}
void DFS(ll v) {
	M[v] = 1 ;
	V.pb(v) ;
	for (auto u : G[v]) {
		if (!M[u]) DFS(u) ;
	}
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> n ;
    for (int c = 0 ;c < 3 ; c ++) {
    	for (int i = 1 ; i <= n ; i ++) {
    		cin >> cost[c][i] ;
		}
	}
	for (int i =0 ; i < n- 1;  i ++) {
		ll v , u ;
		cin >> v >> u ;
		G[v].pb(u) ;
		G[u].pb(v) ;
	}
	for (int i = 1 ; i <= n ; i ++) cnt[G[i].size()] ++ ;
	if (!(cnt[2] == n - 2 && cnt[1] == 2)) return cout << -1 , 0 ;
	for (int i = 1 ; i <= n ; i ++) {
		if (G[i].size() == 1) {
			DFS(i) ;
			break; 
		}
	}
	do{
		f() ;
		
	}while(next_permutation(all(cur))) ;
	cout << ans << '\n' ;
	for (int i = 1;  i <= n ; i++) cout << k[i] + 1 << ' ';    
    
    return (0) ;
}
