#include<bits/stdc++.h>
#define maxn 2105
#define ll long long
using namespace std;
struct edge{int u,v;ll c;}e[maxn*maxn+maxn];
int cmp(edge a,edge b){return a.c<b.c;}
int n,x[maxn],y[maxn],c[maxn],k[maxn],tot;
int fa[maxn],ac[maxn],ax[maxn],ay[maxn];
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),fa[i]=i;
	fa[n+1]=n+1;
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)
	{
		e[++tot]=(edge){i,n+1,c[i]};
		for(int j=i+1;j<=n;j++)
			e[++tot]=(edge){i,j,1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))};
	}
	ll ans=0;
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		int fx=getf(e[i].u),fy=getf(e[i].v);
		if(fx==fy) continue;
		ans+=e[i].c,fa[fx]=fy;
		if(e[i].u==n+1||e[i].v==n+1) ac[++ac[0]]=(e[i].u==n+1?e[i].v:e[i].u);
		else ax[++ax[0]]=e[i].u,ay[ax[0]]=e[i].v;
	}
	printf("%lld\n",ans);
	printf("%d\n",ac[0]);
	for(int i=1;i<=ac[0];i++) printf("%d ",ac[i]); puts("");
	printf("%d\n",ax[0]);
	for(int i=1;i<=ax[0];i++) printf("%d %d\n",ax[i],ay[i]);
	return 0;
}