#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long 
const int maxn = 1e5+10;
const ll INF = 1e17;
vector <int> vec[maxn];
int n;
int du[maxn];
int nxt[maxn];
int a[maxn][4]; 
ll ans;
int f=1;
int c[maxn];
int cns[maxn];
void dfs(int u,int fa)
{
	int v;
	for(int i=0;i<vec[u].size();i++)
	{
		v=vec[u][i];
		if(v==fa) continue;
		if(nxt[u]!=0) 
		{
			f=0;
			return ;
		}
		nxt[u]=v;
		dfs(v,u);
	}
}
int main()
{
	int u,v;
	scanf("%d",&n);
	for(int j=1;j<=3;j++)
		for(int i=1;i<=n;i++)
		    scanf("%d",&a[i][j]);
	ans=INF;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		du[u]++;
		du[v]++;
	    vec[u].push_back(v);
	    vec[v].push_back(u);
	}
	int st=0;
	for(int i=1;i<=n;i++) if(du[i]==1) st=i;
	if(!st)
	{
		printf("-1");
		return 0;
	} 
	dfs(st,0);
	if(!f)
	{
		printf("-1");
		return 0;
	}
	ll bns; int tmp;
	for(int i=1;i<=3;i++)
	{
		c[1]=i;
		for(int j=1;j<=3;j++)
		{
			if(i==j) continue;
			tmp=nxt[st];
		    c[2]=j;
		    bns=a[st][i]+a[tmp][j];
			for(int k=3;k<=n;k++)
		    {
		    	tmp=nxt[tmp];
		    	c[k]=6-c[k-1]-c[k-2];
			    bns+=a[tmp][c[k]];
			}
			if(ans>bns)
			{
				ans=bns;
				tmp=st;
				for(int k=1;k<=n;k++)
				{
					cns[tmp]=c[k];
					tmp=nxt[tmp];
				}
			}
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",cns[i]);
	return 0;
}