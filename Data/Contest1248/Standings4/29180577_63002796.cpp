//	Author : amnptl 
//	   Godbless
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define NeedForSpeed() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD (1000000007); // 1e9+7
int main()
{
	NeedForSpeed();
	ll n,m; cin>>n>>m;
	if(n<m) swap(n,m);

	ll dp[n+1][2][3];
	for(int i=0; i<(n+1); i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<3; k++)
				dp[i][j][k]=0;
	dp[1][1][1] = 1; dp[1][0][1] = 1;

	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<2; j++)
		{
			for(int k=1; k<=2; k++)
			{
				if(k==2)
					dp[i][j][k] = dp[i-1][j][1];
				else
					dp[i][j][k] = dp[i-1][j][1] + dp[i-1][j][2];
				dp[i][j][k] %= MOD;
			}
		}
	}
	ll ans = (dp[n][0][1] + dp[n][0][2] + dp[n][1][1] + dp[n][1][2]);
	ans -= 2; ans %= MOD;

	ll dpm[m+1][2][3];
	for(int i=0; i<(m+1); i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<3; k++)
				dpm[i][j][k]=0;
	dpm[1][1][1] = 1; dpm[1][0][1] = 1;

	for(int i=2; i<=m; i++)
	{
		for(int j=0; j<2; j++)
		{
			for(int k=1; k<=2; k++)
			{
				if(k==2)
					dpm[i][j][k] = dpm[i-1][j][1];
				else
					dpm[i][j][k] = dpm[i-1][j][1] + dpm[i-1][j][2];
				dpm[i][j][k] %= MOD;
			}
		}
	}
	ll buf = (dpm[m][0][1] + dpm[m][0][2] + dpm[m][1][1] + dpm[m][1][2]);
	buf %= MOD;

	ans += buf; ans %= MOD;
	cout<<ans<<endl;
	return 0;
}