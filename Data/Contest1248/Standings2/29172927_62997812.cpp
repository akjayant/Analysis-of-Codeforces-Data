#pragma GCC optimize "03"
#include "bits/stdc++.h"
using namespace std;
 
#define int long long int
#define ld long double
#define pi pair<int, int>
#define pb push_back
#define fi first
#define se second
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#ifndef LOCAL
#define endl '\n'
#endif
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;

int dp[N][4], s[N];

int power(int a, int b){
	int ans = 1;
	while(b){
		if(b&1)
			ans = (ans*a) % mod;
		b >>= 1;
		a = (a*a) % mod;
	}
	return ans;
}

signed main() {
	IOS;
	#ifdef LOCAL
		freopen("input.txt","r", stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n, m;
	cin >> n >> m;
	for(int j = 0; j < 4; j++)
		dp[2][j] = 1;
	s[1] = 2;	s[2] = 4;
	for(int i = 3; i < N; i++){
		dp[i][0] += dp[i-1][2];
		dp[i][1] += dp[i-1][0] + dp[i-1][2];
		dp[i][2] += dp[i-1][1] + dp[i-1][3];
		dp[i][3] += dp[i-1][1];
		for(int j = 0; j < 4; j++){
			dp[i][j] %= mod;
			s[i] = (s[i] + dp[i][j]) % mod;
		}
	}
	cout << (mod + s[m]-2 + s[n]) % mod << endl;
	return 0;
}