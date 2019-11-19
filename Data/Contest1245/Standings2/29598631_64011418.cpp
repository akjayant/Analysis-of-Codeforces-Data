#include <cstdio>
#include <algorithm>
using namespace std;
const int S=2003;
int n,x[S],y[S],k[S],fa[S],b[S],tot=0,cnt=0,su=0;
bool mk[S];
struct info
{
	int x,y;
	long long w;
}a[S*S+S+S];
inline bool cmp(const info &a,const info &b)
{
	return a.w<b.w;
}
inline int fd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
inline int ab(int a){return a>0?a:-a;}
long long res=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[++tot]=(info){0,i,x};
	}
	for (int i=1;i<=n;i++)
		scanf("%d",k+i);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			a[++tot]=(info){i,j,1ll*(ab(x[i]-x[j])+ab(y[i]-y[j]))*(k[i]+k[j])};
	sort(a+1,a+1+tot,cmp);
	for (int i=0;i<=n;i++) fa[i]=i;
	for (int i=1,s=0;i<=tot && s<n;++i)
	{
		int fu,fv;
		fu=fd(a[i].x);
		fv=fd(a[i].y);
		if (fu!=fv)
		{
			fa[fu]=fv;
			if (!a[i].x)
				mk[a[i].y]=true,++su;
			else b[++cnt]=i;
			res+=a[i].w;
		}
	}
	printf("%lld\n%d\n",res,su);
	for (int i=1;i<=n;i++)
		if (mk[i]) printf("%d ",i);
	printf("\n%d\n",cnt);
	for (int i=1;i<=cnt;i++)
		printf("%d %d\n",a[b[i]].x,a[b[i]].y);
	return 0;
}