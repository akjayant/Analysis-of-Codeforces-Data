#include<cstdio>
#include<algorithm>
#define mod 1000000007
using std::swap;
int n,m;
long long dp[100100];
int main()
{
	scanf("%d%d",&n,&m);
	if(n<m)
		swap(n,m);
	dp[0]=2;
	for(int i=0;i<n;i++)
	{
		dp[i+1]=(dp[i+1]+dp[i])%mod;
		dp[i+2]=(dp[i+2]+dp[i])%mod;
	}
	long long ans=(dp[n]+dp[m]-2+mod)%mod;
	printf("%I64d\n",ans);
	return 0;
}
