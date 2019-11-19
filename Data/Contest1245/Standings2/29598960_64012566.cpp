#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n;
ll x[2005],y[2005],c[2005],k[2005],fa[2005];
struct EE
{
	int u,v;
	ll c;
	bool f;
	bool operator <(const EE &b)const
	{
		return c<b.c;
	}
};
int f(int x)
{
	return fa[x]==x?x:fa[x]=f(fa[x]);
}
bool merge(int x,int y)
{
	x=f(x),y=f(y);
	if(x!=y)
		return fa[x]=y,true;
	return false;
}
vector<EE>e;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",x+i,y+i);
	for(int i=1;i<=n;i++)scanf("%lld",c+i);
	for(int i=1;i<=n;i++)scanf("%lld",k+i);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)e.push_back({i,j,(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])),0});
	for(int i=1;i<=n;i++)e.push_back({n+1,i,c[i],0});
	sort(e.begin(),e.end());
	for(int i=1;i<=n+1;i++)fa[i]=i;
	ll ans=0;
	for(auto &ee:e)
	{
		int u=ee.u,v=ee.v,c=ee.c;
		if(merge(u,v))
			ee.f=1,ans+=ee.c;
	}
	printf("%lld\n",ans);
	int ans1=0,ans2=0;
	for(auto ee:e)
		if(ee.f)
		{
			if(ee.u>n)
				++ans1;
			else
				++ans2;
		}
	printf("%d\n",ans1);
	for(auto ee:e)
		if(ee.f&&ee.u>n)
			printf("%d ",ee.v);
	printf("\n%d\n",ans2);
	for(auto ee:e)
		if(ee.f&&ee.u<=n)
			printf("%d %d\n",ee.u,ee.v);
	return 0;
}