#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=1e5+9,INF=1e18;
struct Edge
{
	LL v;
}E[N<<1];
LL n,ans=INF,tim=0;
LL last=0,first[N],nxt[N<<1],deg[N];
LL c[5][N],s[N],p[N];
template<typename T>
inline void read(T &x)
{
	x=0;T w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;	c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';	c=getchar();}
	x*=w;
}
void add(LL u,LL v)
{
	E[++last].v=v;
	nxt[last]=first[u];
	first[u]=last;
	++deg[v];
}
void dfs(LL u,LL fa)
{
	p[++tim]=u;
	for(LL i=first[u];i;i=nxt[i])
	{
		LL v=E[i].v;
		if(v==fa)	continue;
		dfs(v,u);
	}
}
void calc(LL a,LL b)
{
	LL sum=0;
	for(LL i=1;i<=n;++i)
	{
		if(i%3==1)	sum+=c[a][p[i]];
		else if(i%3==2)	sum+=c[b][p[i]];
		else	sum+=c[a^b][p[i]];
	}
	if(sum<ans)
	{
		ans=sum;
		for(LL i=1;i<=n;++i)
		{
			if(i%3==1)	s[p[i]]=a;
			else if(i%3==2)	s[p[i]]=b;
			else	s[p[i]]=a^b;
		}
	}
}
int main()
{
	read(n);
	for(LL i=1;i<=3;++i)
		for(LL j=1;j<=n;++j)
			read(c[i][j]);
	for(LL i=1;i<=n-1;++i)
	{
		LL u,v;
		read(u);read(v);
		add(u,v);
		add(v,u);
	}
	for(LL i=1;i<=n;++i)
	{
		if(deg[i]>=3)
		{
			printf("-1");
			return 0;
		}
	}
	for(LL i=1;i<=n;++i)
	{
		if(deg[i]==1)
		{
			dfs(i,0);
			break;
		}
	}
	calc(1,2);
	calc(1,3);
	calc(2,1);
	calc(2,3);
	calc(3,1);
	calc(3,2);
	printf("%I64d\n",ans);
	for(LL i=1;i<=n;++i)
		printf("%I64d ",s[i]);
	return 0;
}