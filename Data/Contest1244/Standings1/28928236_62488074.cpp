#include<bits/stdc++.h>
#define mz 1000000007
using namespace std;

vector <int> v[100005];
int c[100005][5];
int a[100005],num[100005];
long long dp[100005][5][5];

void dfs(int x,int cnt,int fa)
{
	a[cnt]=x;
	for(int i=0;i<v[x].size();i++)
	{
		if(v[x][i]!=fa)
			dfs(v[x][i],cnt+1,x);
	}
}

int main()
{
	bool flag=0;
    int n,x,y,t;
    long long ans;
    scanf("%d",&n);
    for(int i=0;i<3;i++)
    	for(int j=1;j<=n;j++)
    		scanf("%d",&c[j][i]);
    for(int k=1;k<=n;k++)
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				dp[k][i][j]=n*10LL*mz;
	ans=n*10LL*mz;
    for(int i=1;i<n;i++)
    {
    	scanf("%d%d",&x,&y);
    	v[x].push_back(y);
    	v[y].push_back(x);
    	if(v[x].size()>2 || v[y].size()>2)
    		flag=1;
	}
	if(flag)
		printf("-1\n");
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(v[i].size()==1)
			{
				dfs(i,1,0);
				break;
			}
		}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				if(i+j<=3 && i!=j)
					dp[2][i][j]=min(dp[2][i][j],0LL+c[a[1]][i]+c[a[2]][j]);
			}
		for(int i=3;i<=n;i++)
		{
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
				{
					if(k+j<=3 && k!=j)
						dp[i][j][k]=min(dp[i][j][k],dp[i-1][3-j-k][j]+c[a[i]][k]);
				}
		}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				if(i+j<=3 && i!=j)
				{
					if(dp[n][i][j]<ans)
					{
						x=i;
						y=j;
						ans=dp[n][i][j];
					}
				}
			}
		num[a[n]]=y+1;
		for(int i=n-1;i>=1;i--)
		{
			t=y;
			y=x;
			x=3-y-t;
			num[a[i]]=y+1;
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",num[i]);
	}
	return 0;
}
