#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cost[4][100007];
vector<int> e[100007];
int t[100007];
int as[100007];
int du[100007];
int vis[100007];
int use[4];
ll ans=-1;
int n;
void dfs(int x,ll sum)
{
	int sz=e[x].size();
	if(sz==1)
	{
		if(ans==-1)
		{
			ans=sum;
			for(int i=1;i<=n;i++)
				as[i]=t[i];	
		}
		else
		{
			if(sum<ans)
			{
				ans=sum;
				for(int i=1;i<=n;i++)
					as[i]=t[i];	
			}
		}
		return ;
	}
	for(int i=0;i<sz;i++)
	{
		int v=e[x][i];
		if(vis[v]!=1)
		{
			vis[v]=1;
			for(int w=1;w<=3;w++)
			{
				if(w!=use[1]&&w!=use[2])
				{
					sum+=cost[w][v];
					t[v]=w;
					use[1]=use[2];
					use[2]=w;
					break;
				}
			}
			dfs(v,sum);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld",&cost[i][j]);
	int flag=0;
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		du[u]++;
		du[v]++;
		if(du[u]==3||du[v]==3)
			flag=1;
	}
	if(flag)
	{
		printf("-1\n");
		return 0;
	}
	int gen=-1;
	for(int i=1;i<=n;i++)
	{
		if(du[i]==1)
		{
			gen=i;
			break;
		}
	}
	if(gen==-1)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			if(i==j)
				continue;
			for(int i=1;i<=n;i++)
				vis[i]=0;
			int temp=e[gen][0];
			use[1]=i;
			use[2]=j;
			vis[gen]=1;
			vis[temp]=1;
			t[gen]=i;
			t[temp]=j;
			dfs(temp,cost[i][gen]+cost[j][temp]);
		}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++)
		printf("%d%c",as[i]," \n"[i==n]);
	return 0;
	
}