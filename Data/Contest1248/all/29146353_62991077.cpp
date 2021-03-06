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

ll f[2][N] ;
ll sum(ll a , ll b) {
	return (a + b) % Mod ;
}
ll sub(ll a , ll b) {
	return (a - b + Mod) % Mod ;
}
// 0 white 
ll dp[2][N] ;
// 0 good 
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    f[0][1] = f[1][1] = 1 ;
    f[0][2] = f[1][2] = 2 ;
    for (int i = 3;  i < N ;i ++) {
    	f[0][i] = sum(f[1][i - 1] , f[1][i - 2]) ;
    	f[1][i] = sum(f[0][i - 1] , f[0][i - 2]) ;
	}
	ll n ,m ;
	cin >> n >> m ;
	if (m < n) swap(n , m) ;
	ll k = sum(f[0][m] , f[1][m]) ;
	ll bad = sub(k , 2) ;
	ll good = 2 ;
	dp[0][1] = 2 ;
	dp[1][1] = bad ;
	//cout << bad << endl;
	for (int i = 2 ; i <= n ; i ++) {
		dp[0][i] = (dp[0][i - 1] * 2 ) % Mod ;
		dp[1][i] = dp[1][i - 1] ;
	}
	cout << sum(sum(f[0][n ] , f[1][n]) , dp[1][n]);
    
    return (0) ;
}
