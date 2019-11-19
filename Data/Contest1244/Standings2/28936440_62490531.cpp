#include<bits/stdc++.h>
using namespace std;
#define int long long
const int size=1e5+5;
typedef long long LL;
const LL inf=1e18;
int col[3][size];
int anscol[size];
vector<int> G[size];
int du[size];
LL dfs(int u,int f,int c1,int c2)
{
	int nc=3-c1-c2;
	anscol[u]=nc;
	LL ret=col[nc][u];
	for(auto v:G[u])
	{
		if(v==f) continue;
		ret+=dfs(v,u,c2,nc);
	}
	return ret;
}
int32_t main()
{
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&col[0][i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&col[1][i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&col[2][i]);
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		du[u]++;
		du[v]++;
	}
	int s=-1;
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		if(du[i]==1) s=i;
		if(du[i]>2) flag=false;
	}
	if(!flag) puts("-1");
	else
	{
		LL ans=inf;
		int s1=G[s][0];
		int s2;
		for(auto t:G[s1]){if(t!=s) s2=t;}
		int a,b;
		for(int i=0;i<=2;i++)
		{
			for(int j=0;j<=2;j++)
			{
				if(i==j) continue;
				LL tans=col[i][s]+col[j][s1]+dfs(s2,s1,i,j);
				if(tans<ans)
				{
					a=i,b=j;
					ans=tans;
				}
			}
		}
		printf("%lld\n",ans);
		dfs(s2,s1,a,b);
		anscol[s]=a,anscol[s1]=b;
		for(int i=1;i<=n;i++)
		{
			printf("%lld%c",anscol[i]+1,i==n?'\n':' ');
		}
	}
}
	