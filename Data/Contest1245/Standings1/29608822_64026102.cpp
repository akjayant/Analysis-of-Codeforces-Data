#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
const ll inf=9e18;
const int MAXN=2019;
struct node
{
	int c,k,x,y,id;
	bool operator < (const node &rhs) const
	{
		return c>rhs.c;
	}
}p[MAXN];
ll calc(node i,node j)
{
	return 1LL*(i.k+j.k)*(abs(i.x-j.x)+abs(i.y-j.y));
}
struct Edge
{
	int u,v;
	ll c;
	Edge(int u=0,int v=0,ll c=0):u(u),v(v),c(c){}
	bool operator < (const Edge &rhs) const
	{
		return c<rhs.c;
	}
}E[MAXN*MAXN+MAXN];
int n,m=0,s=0,t[MAXN],e=0,ea[MAXN],eb[MAXN];
int fa[MAXN];
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
ll ans=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		p[i].id=i;
		p[i].x=read();
		p[i].y=read();
	}
	for(int i=1;i<=n;++i)
		p[i].c=read();
	for(int i=1;i<=n;++i)
		p[i].k=read();
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;
		E[++m]=Edge(i,n+1,p[i].c);
		for(int j=i+1;j<=n;++j)
			E[++m]=Edge(i,j,calc(p[i],p[j]));
	}
	fa[n+1]=n+1;
	sort(E+1,E+1+m);
	int tot=0;
	for(int i=1;i<=m && tot<=n;++i)
	{
		int u=E[i].u,v=E[i].v;
		if(Find(u)!=Find(v))
		{
			fa[Find(u)]=Find(v);
			if(v==n+1)
				t[++s]=u;
			else
			{
				++e;
				ea[e]=u;
				eb[e]=v;	
			}
			++tot;
			ans+=E[i].c;
		}
	}
	cout<<ans<<endl;
	printf("%d\n",s);
	for(int i=1;i<=s;++i)
		printf("%d ",t[i]);
	printf("\n%d\n",e);
	for(int i=1;i<=e;++i)
		printf("%d %d\n",ea[i],eb[i]);
	return 0;
}
