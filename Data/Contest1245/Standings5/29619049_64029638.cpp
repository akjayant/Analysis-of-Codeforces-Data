
#include<cstdio>
#include<cmath>
 #include<bits/stdc++.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define inf 0x3fffffff
const int mod=1e9+7;
const int maxn=2005;
using namespace std;
int n,f[maxn*maxn],tot,tot1,tot2;
long long a[maxn],b[maxn],k[maxn],xx[maxn],yy[maxn],cc[maxn];
struct node
{
	int x,y;
	long long w;
}e[maxn*maxn];
bool cmp(node xx,node yy)
{
	return xx.w<yy.w;
}
int findd(int x)
{
	if (f[x]==x) return x;
	else return f[x]=findd(f[x]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
	}
	for (int i=1;i<=n;i++)
	{
		long long x;
		scanf("%lld",&x);
		e[++tot].x=0;
		e[tot].y=i;
		e[tot].w=x;
	}
	for (int i=1;i<=n;i++) scanf("%lld",&k[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			e[++tot].x=i;
			e[tot].y=j;
			e[tot].w=(k[i]+k[j])*(abs(a[i]-a[j])+abs(b[i]-b[j]));
		}
	}
//	puts("1");
	for (int i=0;i<=n;i++) f[i]=i;
	int cnt=0;
	sort(e+1,e+1+tot,cmp);
	long long ans=0;
	for (int i=1;i<=tot;i++)
	{
		int fx=findd(e[i].x),fy=findd(e[i].y);
		if (fx==fy) continue;
		cnt++;
		f[fy]=fx;
		ans+=e[i].w;
	    //printf("%lld\n",e[i].w);
		if (e[i].x==0)
		{
			cc[++tot1]=e[i].y;
		}
		else
		{
			xx[++tot2]=e[i].x;
			yy[tot2]=e[i].y;
		}
	}
	printf("%lld\n",ans);
	printf("%d\n",tot1);
	for (int i=1;i<=tot1;i++) printf("%lld ",cc[i]);
	printf("\n");
	printf("%d\n",tot2);
	for (int i=1;i<=tot2;i++) printf("%lld %lld\n",xx[i],yy[i]);
	
	
}
