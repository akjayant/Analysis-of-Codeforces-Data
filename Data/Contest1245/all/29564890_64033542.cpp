#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int book[101][101];
double dp[201][2];
pair<int,int>rev[10001];
signed main() 
{
	int n=10;
	int cnt=0;
	for(int i=n;i>=1;i--)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				book[i][j]=++cnt;
				rev[cnt]=make_pair(i,j);
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				book[i][j]=++cnt;
				rev[cnt]=make_pair(i,j);
			}
		}
	}
	dp[cnt][0]=dp[cnt][1]=0;
	for(int i=2;i<=7;i++)
	{
		for(int j=1;j<=i-1;j++)
		{
			dp[book[n][i]][0]=6;
			dp[book[n][i]][1]=99999999;
		}
	}
	for(int i=cnt-7;i>=1;i--)
	{
		int x=rev[i].first,y=rev[i].second;
		for(int j=1;j<=6;j++)
			dp[i][0]+=min(dp[i+j][1],dp[i+j][0]);
		dp[i][0]/=6;
		dp[i][0]++;
		if(a[x][y])
			dp[i][1]=dp[book[x+a[x][y]][y]][0];
		else dp[i][1]=99999999;
	}
	/*for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%5.2lf ",min(dp[book[i][j]][1],dp[book[i][j]][0]));
		printf("\n");
	}*/
	printf("%.10lf",min(dp[1][1],dp[1][0]));
	return 0;
}
