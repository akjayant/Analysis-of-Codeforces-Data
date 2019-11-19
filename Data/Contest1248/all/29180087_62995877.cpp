#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll unsigned long long
#define MAXN 100100 
ll n, m, dp[MAXN], ans, d[5][5], mod=1e9+7;
int main()
{
	cin>>n>>m;
	d[1][1] = 2;
	d[1][2] = 4;
	d[2][1] = 4;
	d[2][2] = 6;
	if(n<=2 && m<=2)
	{
		cout<<d[n][m]<<endl;
		return 0;
	}
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=max(n, m);i++)
	{
		dp[i] = (dp[i-1] + dp[i-2])%mod;
//		cout<<dp1[i]<<endl;
	}
	ans = (dp[n] + dp[m] - 1ll + mod) % mod;
	ans = (ans*2)%mod;
	cout<<ans<<endl;
	
	return 0;
} 
