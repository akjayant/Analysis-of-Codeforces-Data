#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 4000002
typedef long long ll;
struct lian
{
	int x,y;
	ll len;
}lns[N];
int n,tot;
int a[N][2];
int b[N],c[N];
int f[N];
int as[N][2],js,fk[N],zz;
int getroot(int t)
{
	if(f[t]==-1)return t;
	else return f[t]=getroot(f[t]);
}
bool cmp(lian a,lian b)
{
	return a.len<b.len;
}
int main()
{memset(f,-1,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			lns[++tot].x=i;
			lns[tot].y=j;
			lns[tot].len=1ll*(abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]))*(c[i]+c[j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		lns[++tot].x=i;
		lns[tot].y=n+1;
		lns[tot].len=b[i];
	}
	sort(lns+1,lns+1+tot,cmp);
	ll ans=0;
	for(int i=1;i<=tot;i++)
	{lian te=lns[i];
		int x=getroot(te.x),y=getroot(te.y);
		if(x^y)
		{
			f[x]=y;
			ans+=te.len;
			as[++js][0]=te.x,as[js][1]=te.y;
		}
	}printf("%I64d\n",ans);
	int tcn=js;
	for(int i=1;i<=js;i++)
	{
		if(as[i][1]==n+1)fk[++zz]=as[i][0],tcn--;
	}printf("%d\n",zz);
	for(int i=1;i<=zz;i++)printf("%d ",fk[i]);puts("");
	printf("%d\n",tcn);
	for(int i=1;i<=js;i++)
	{
		if(as[i][1]!=n+1)printf("%d %d\n",as[i][0],as[i][1]);
	}
}

