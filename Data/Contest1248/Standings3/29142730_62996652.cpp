#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 100010;
int n, m;

ll ans = 0;
ll dp[maxn];


int main(){
	scanf("%d%d", &n, &m);
	dp[0] = 1;
	for(register int i = 0; i <= n; i ++){
		(dp[i + 1] += dp[i]) %= mod;
		(dp[i + 2] += dp[i]) %= mod;
	}
	ans += dp[n];
	//cout<<dp[n]<<endl;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(register int i = 0; i <= m; i ++){
		(dp[i + 1] += dp[i]) %= mod;
		(dp[i + 2] += dp[i]) %= mod;
	}
	(ans += dp[m]) %= mod;
	//cout<<dp[m]<<endl;
	ans --;
	ans = ((ans * 2) + mod) % mod;
	printf("%lld\n", ans);

	return 0;
}