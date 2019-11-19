#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;
struct edge{int v,next;long long w;bool sel;edge(){sel=false;}edge(int _v,long long _w,int _next){v=_v;w=_w;next=_next;sel=false;}}e[5000001];int head[20001],sz;void init(){memset(head,-1,sizeof(head));sz=1;}
void insert(int u,int v,long long w){e[++sz]=edge(v,w,head[u]);head[u]=sz;}
struct node{long long d;int num;node(){}node(long long _d,int _num){d=_d;num=_num;}bool operator<(const node &b)const{return d>b.d;}};
int q[10001],pre[10001];bool vis[10001];long long dis[10001];
int prim(int s)
{
	priority_queue<node> pq;pq.push(node(0,s));long long ans=0;memset(dis,0x3f,sizeof(dis));dis[s]=0;
	while(!pq.empty())
	{
		int p=pq.top().num;pq.pop();if(vis[p])continue;vis[p]=true;e[pre[p]].sel=true;ans+=e[pre[p]].w;
		for(int i=head[p];~i;i=e[i].next)if(dis[e[i].v]>e[i].w){dis[e[i].v]=e[i].w;pre[e[i].v]=i;pq.push(node(dis[e[i].v],e[i].v));}
	}
	return ans;
}
int x[100001],y[100001],c[100001],k[100001],n;
signed main()
{
	scanf("%lld",&n);init();for(int i=1;i<=n;++i)scanf("%lld%lld",&x[i],&y[i]);for(int i=1;i<=n;++i)scanf("%lld",&c[i]);for(int i=1;i<=n;++i)scanf("%d",&k[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=i+1;j<=n;++j)
		{
			insert(i,j,1ll*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]));
			insert(j,i,1ll*(abs(x[i]-x[j])+abs(y[i]-y[j]))*(k[i]+k[j]));
		}
	}
	for(int i=1;i<=n;++i)insert(n+1,i,c[i]),insert(i,n+1,c[i]);
	printf("%lld\n",prim(1));int cntp=0;
	for(int i=head[n+1];~i;i=e[i].next)if(e[i].sel||e[i^1].sel)++cntp;printf("%lld\n",cntp);
	for(int i=head[n+1];~i;i=e[i].next)if(e[i].sel||e[i^1].sel)printf("%lld ",e[i].v);printf("\n");printf("%lld\n",n-cntp);
	for(int i=1;i<=n;++i)
	{
		for(int j=head[i];~j;j=e[j].next)
		{
			if(e[j].sel&&e[j].v!=n+1)printf("%lld %lld\n",i,e[j].v);
		}
	}
	return 0;
}