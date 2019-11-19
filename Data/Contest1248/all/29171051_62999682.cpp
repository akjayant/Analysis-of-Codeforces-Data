#include<stdio.h>
#define MOD 1000000007
int dp[100005][2];
int n,m;
int dp_[100005][2];
int main()
{
	dp[1][0]=2;
	dp[2][0]=2;dp[2][1]=2;
	for(int i=3;i<100001;i++)
	{
		dp[i][0]=dp[i-1][1]+dp[i-1][0];
		dp[i][1]=dp[i-1][0];
		dp[i][1]%=MOD;
		dp[i][0]%=MOD;
	}
	dp_[1][0]=2;//ys
	for(int i=2;i<100001;i++)
	{
		dp_[i][0]=dp_[i-1][0]+dp_[i-1][1];
		dp_[i][1]=dp_[i-1][0];
		dp_[i][0]%=MOD;dp_[i][1]%=MOD;
	}
	scanf("%d%d",&n,&m);
	int ans=-2;
	ans+=dp[n][0];
	ans%=MOD;
	ans+=dp[n][1];
	ans%=MOD;
	ans+=dp_[m][1];
	ans%=MOD;
	ans+=dp_[m][0];
	ans%=MOD;
	printf("%d\n",(int)ans);
//	printf("%d\n",dp[m][1]+dp[m][0]+2*(n-1));
	return 0;
}