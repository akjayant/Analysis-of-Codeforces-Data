#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+50;
int n,m;
LL dp[N][2][2];
void up(LL &x,LL t)
{
	x=(x+t)%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	dp[1][0][0]=1;
	dp[1][1][0]=1;
	for(int i=2;i<=max(n,m);i++)
	{
		up(dp[i][0][1],dp[i-1][0][0]);
		up(dp[i][1][1],dp[i-1][1][0]);
		up(dp[i][1][0],dp[i-1][0][0]+dp[i-1][0][1]);
		up(dp[i][0][0],dp[i-1][1][0]+dp[i-1][1][1]);
	}
	LL sum=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			sum+=dp[n][i][j]+dp[m][i][j];
	printf("%lld\n",(sum-2+mod)%mod);
	return 0;
}