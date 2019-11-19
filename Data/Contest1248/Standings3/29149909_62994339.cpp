#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define INF 1000000000ll
#define MAX 100005

void init(){
	return;
}

ll add(ll a, ll b){
	return (a+b)%mod;
}

ll solve(ll n){
	ll dp[4][n];
	memset(dp, 0ll, sizeof(dp));
	for(int i = 0; i<n; i++){
		if(i == 0){
			dp[0][i] = 0;
			dp[1][i] = 1;
			dp[2][i] = 1;
			dp[3][i] = 0;
		}
		else if(i == 1){
			dp[0][i] = 1;
			dp[1][i] = 1;
			dp[2][i] = 1;
			dp[3][i] = 1;
		}
		else{
			dp[0][i] = add(dp[1][i-2] , dp[3][i-2]);
			dp[1][i] = add(dp[3][i-2] , add( dp[2][i-2] , dp[1][i-2]));
			dp[2][i] = add(dp[0][i-2], add(dp[1][i-2], dp[2][i-2]));
			dp[3][i] = add(dp[0][i-2], dp[2][i-2]);
		}
	//	cout << dp[0][i] << " " << dp[1][i] << " " << dp[2][i] << " " << dp[3][i] << endl;
	}
	return add(add(dp[0][n-1], dp[1][n-1]), add(dp[2][n-1], dp[3][n-1]));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	ll n, m;
	cin >> n >> m;
	ll ans = 0ll;
	ans = (ans + solve(n))%mod;
	ans = (ans + solve(m))%mod;
	ans = (ans - 2ll + mod)%mod;
	cout << ans << endl;
	//fclose(stdout);
	return 0;
}