#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2010
int fa[N],c[N],k[N],n,x[N],y[N],idx,id[N]; bool is[N*N]; long long ans;
struct Edge {int x,y;long long val;}edge[N*N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
bool cmp(const Edge &a,const Edge &b) {return a.val<b.val;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),fa[i]=i;
	for(int i=1;i<=n;i++) scanf("%d",&k[i]),id[i]=i;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
		edge[++idx]=(Edge){i,j,1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]))};
	sort(edge+1,edge+idx+1,cmp);
	for(int i=1;i<=idx;i++)
	{
		int fa_x=find(edge[i].x),fa_y=find(edge[i].y);
		if(fa_x==fa_y||(fa_x!=fa_y&&max(c[id[fa_x]],c[id[fa_y]])<=edge[i].val)) continue;
		fa[fa_x]=fa_y,is[i]=true,ans+=edge[i].val;
		if(c[id[fa_x]]<c[id[fa_y]]) id[fa_y]=id[fa_x];
	}
	for(int i=1;i<=n;i++) if(find(i)==i) ans+=c[id[i]];
	printf("%lld\n",ans),ans=0;
	for(int i=1;i<=n;i++) if(find(i)==i) ans++;
	printf("%lld\n",ans),ans=0;
	for(int i=1;i<=n;i++) if(find(i)==i) printf("%d ",id[i]); printf("\n");
	for(int i=1;i<=idx;i++) if(is[i]) ans++;
	printf("%lld\n",ans),ans=0;
	for(int i=1;i<=idx;i++) if(is[i]) printf("%d %d\n",edge[i].x,edge[i].y);
}