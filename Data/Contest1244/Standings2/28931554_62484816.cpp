#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
namespace Dango
{
	const int MAXN=100005;
	long long INF=0x3f3f3f3f3f3f3f3f;
	int n;
	long long c[MAXN][3];
	int head[MAXN],to[MAXN<<1],nxt[MAXN<<1];
	int du[MAXN],s;
	int d[MAXN];
	long long val[3][3],res,ans;
	int color[3];
	int read()
	{
		int x=0,f=0;
		char ch=getchar();
		while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
		while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
		return f?-x:x;
	}
	void add(int u,int v)
	{
		static int cnt;
		cnt++;
		to[cnt]=v;
		nxt[cnt]=head[u];
		head[u]=cnt;
	}
	void dfs(int u,int f)
	{
		d[u]=(d[f]+1)%3;
		for(int i=0;i<3;i++)
		{
			val[d[u]][i]+=c[u][i];
		}
		for(int i=head[u];i;i=nxt[i])
		{
			int v=to[i];
			if(v==f)continue;
			dfs(v,u);
		}
	}
	void dfs(int a)
	{
		static int vis[3];
		if(a>=3)
		{
			if(ans>res)
			{
				ans=res;
				for(int i=0;i<3;i++)
					color[vis[i]-1]=i;
			}
			return;
		}
		for(int i=0;i<3;i++)
		{
			if(vis[i])continue;
			vis[i]=a+1;
			res+=val[a][i];
			dfs(a+1);
			res-=val[a][i];
			vis[i]=0;
		}
	}
	int work()
	{
		n=read();
		for(int i=0;i<3;i++)
			for(int j=1;j<=n;j++)
				c[j][i]=read();
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
			du[u]++;du[v]++;
			if(du[u]>2||du[v]>2){printf("-1");return 0;}
		}
		for(int i=1;i<=n;i++)
			if(du[i]==1)s=i;
		dfs(s,0);
		ans=INF;
		dfs(0);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)
			printf("%d ",color[d[i]]+1);
		return 0;
	}
}
int main()
{
	return Dango::work();
}