#include <bits/stdc++.h>

using namespace std;
#define int long long
#define inf 1e18
vector<int>v;
vector<int>e[100001];
void get(int u,int fa)
{
	v.push_back(u);
	for(int i=0;i<e[u].size();i++)
		if(e[u][i]!=fa)
			get(e[u][i],u);
}
int n;
int ans[4][4];
int rem[4][4][100001];
int a[10001][4];
int p[10001];
int curx,cury;
void dfs(int i,int j,int x)
{
	if(x==n+1) return;
	for(int k=1;k<=3;k++)
		if(k!=i&&k!=j)
		{
			dfs(k,i,x+1);
			ans[curx][cury]+=a[v[x]][k];
			rem[curx][cury][x]=k;
		}	
}
signed main() 
{
	scanf("%I64d",&n);
	for(int k=1;k<=3;k++)
		for(int i=1;i<=n;i++)
			scanf("%I64d",&a[i][k]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%I64d%I64d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		if(e[u].size()>=3||e[v].size()>=3)
		{
			printf("-1");
			return 0;
		}
	}
	int at=0;
	for(int i=1;i<=n;i++)
		if(e[i].size()==1)
			at=i;
	v.push_back(0);
	get(at,at);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(i!=j)
			{
				curx=i,cury=j;
				ans[i][j]+=a[v[1]][i];
				ans[i][j]+=a[v[2]][j];
				rem[i][j][1]=i;
				rem[i][j][2]=j;
				dfs(j,i,3);
				
			}
	int mn=inf,at1=0,at2=0;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(i!=j)
			{
				if(ans[i][j]<mn)
					mn=ans[i][j],at1=i,at2=j;
			}
	printf("%I64d\n",mn);
	for(int k=1;k<=n;k++)
		p[v[k]]=rem[at1][at2][k];
	for(int k=1;k<=n;k++)
		printf("%I64d ",p[k]);
	return 0;
}
/*
30 60 3 2
*/