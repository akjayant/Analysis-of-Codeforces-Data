/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

LL n,m,dp[100010][2];

int main()
{
	cin>>n>>m;
	dp[1][1]=2;
	dp[1][2]=0;
	for(int i=2;i<=max(n,m);i++)
	{
		dp[i][1]=(dp[i-1][1]+dp[i-1][2])%MOD;
		dp[i][2]=dp[i-1][1];
	}
	cout<<(dp[n][1]+dp[n][2]-2+dp[m][1]+dp[m][2])%MOD<<endl;
	return 0;
}