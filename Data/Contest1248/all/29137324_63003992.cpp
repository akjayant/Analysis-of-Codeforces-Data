#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef long long ll;
const int N = 2e5+5, mod = 1e9+7;
ll dp[N][2], n, m;
int main()
{
	cin >> n >> m;
	if(n > m) swap(n, m);
	dp[1][0] = 2;
	for(int i=2; i<=m; i++)
	{
		dp[i][0] = dp[i-1][0] + dp[i-1][1], dp[i][0] %= mod;
		dp[i][1] = dp[i-1][0], dp[i][1] %= mod;
	}
	ll tmp = (dp[m][0]+dp[m][1]-2+mod)%mod;
	cout << (tmp + (dp[n][0]+dp[n][1])%mod)%mod << endl;
}