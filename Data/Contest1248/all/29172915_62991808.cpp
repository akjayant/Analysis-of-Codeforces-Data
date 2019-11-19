#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll dp[100005][2];//0 yiyang;1 buyiyang
ll md=1e9+7;
int main()
{
	ll n,i,j,m;
	scanf("%lld %lld",&n,&m);
	dp[1][1]=2;
	dp[1][0]=0;
	ll num=max(n,m);
	for(i=2;i<=num;i++) 
	{
		dp[i][1]=(dp[i-1][1]+dp[i-1][0])%md;
		dp[i][0]=dp[i-1][1]%md;
	}
	ll ans=((dp[n][0]+dp[n][1]+dp[m][0]+dp[m][1])%md-2+md)%md;
	printf("%lld\n",ans);
	return 0;
}