#include<algorithm>
#include<iostream>
#include<complex>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<ctime>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define N 2039
#define mod 20070831
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int n,x[N],y[N],cost[N],stp[N],vis[N],fa[N],pnt[N],tot,u[N],v[N];
ll now[N],dis[N][N],ans;
int main()
{
	scanf("%d",&n);
	for(int a=1;a<=n;a++) scanf("%d%d",&x[a],&y[a]);
	for(int a=1;a<=n;a++)
	{
		scanf("%d",&cost[a]);
		now[a]=cost[a];
	}
	for(int a=1;a<=n;a++) scanf("%d",&stp[a]);
	for(int a=1;a<n;a++)
	{
		for(int b=a+1;b<=n;b++)
		{
			dis[a][b]=dis[b][a]=((ll)stp[a]+stp[b])*(abs(x[b]-x[a])+abs(y[b]-y[a]));
		}
	}
	now[0]=(ll)inf*inf;
	for(int a=1,b;a<=n;a++)
	{
		b=0;
		for(int c=1;c<=n;c++)
		{
			if(!vis[c] && now[c]<now[b])
			{
				b=c;
			}
		}
		ans+=now[b],vis[b]=1;
		if(!fa[b]) pnt[++pnt[0]]=b;
		else tot++,u[tot]=b,v[tot]=fa[b];
		for(int c=1;c<=n;c++)
		{
			if(dis[b][c]<now[c])
			{
				now[c]=dis[b][c];
				fa[c]=b;
			}
		}
	}
	printf("%I64d\n%d\n",ans,pnt[0]);
	for(int a=1;a<=pnt[0];a++) printf("%d ",pnt[a]);
	printf("\n%d\n",tot);
	for(int a=1;a<=tot;a++)
	{
		printf("%d %d\n",u[a],v[a]);
	}
	return 0;
}
/*Kamii_Sinogi*/