#include <bits/stdc++.h>
using namespace std;
const int maxn=2005,maxm=4002005;
typedef pair <int,int> P;
P ans2[maxm];
struct edge { int u,v; long long len; } e[maxm];
int n,m,p1,p2,x[maxn],y[maxn],A[maxn],B[maxn],ans1[maxn],com[maxn];
bool boo[maxn];
long long ans;
int finds(int A) { return com[A]<0?A:com[A]=finds(com[A]); }
bool cmp(edge A,edge B) { return A.len<B.len; }
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) scanf("%d",&B[i]);
	for (int i=1;i<=n;i++) e[i].u=i,e[i].v=i,e[i].len=A[i];
	m=n;
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			m++;
			e[m].u=i;
			e[m].v=j;
			e[m].len=(long long)(B[i]+B[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
		}
	sort(e+1,e+1+m,cmp);
	memset(com,-1,sizeof(com));
	for (int i=1,x,y;i<=m;i++)
	{
		if (e[i].u==e[i].v)
		{
			x=finds(e[i].u);
			if (boo[x]) continue;
			boo[x]=true;
			ans+=e[i].len;
			ans1[++p1]=e[i].u;
		} else
		{
			x=finds(e[i].u);
			y=finds(e[i].v);
			if (x==y) continue;
			if (boo[x]&boo[y]) continue;
			boo[x]=boo[y]=boo[x]|boo[y];
			if (com[x]<com[y]) com[x]+=com[y],com[y]=x; else
			com[y]+=com[x],com[x]=y;
			ans+=e[i].len;
			ans2[++p2]=P(e[i].u,e[i].v);
		}
	}
	printf("%I64d\n%d\n",ans,p1);
	for (int i=1;i<=p1;i++) printf("%d ",ans1[i]);
	printf("\n%d\n",p2);
	for (int i=1;i<=p2;i++) printf("%d %d\n",ans2[i].first,ans2[i].second);
	return 0;
}
