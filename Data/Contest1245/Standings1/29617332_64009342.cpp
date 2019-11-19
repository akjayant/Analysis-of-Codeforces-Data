#include<bits/stdc++.h>

using namespace std;
const int N=11000;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long LL;

int n;
int x[N],y[N];
int c[N],k[N];
LL ans;
int pp[N],fa[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
vector<int> nn;
vector<pair<int,int> > way;
struct edge
{
	int x,y;
	LL w;
	friend bool operator < (edge a,edge b)
	{
		if (a.w!=b.w) return a.w<b.w;
		if (a.x!=b.x) return a.x<b.x;
		return a.y<b.y;
	}
};
vector<edge> e;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d %d",&x[i],&y[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		e.pb({0,i,(LL)c[i]});
		fa[i]=i;
	}
	for (int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			LL dis=abs(x[i]-x[j])+abs(y[i]-y[j]);
			LL coef = (LL)(k[i]+k[j]);
			LL cost=dis*coef;
			e.pb({i,j,cost});
		}
	sort(e.begin(),e.end());
	for (int i=0;i<e.size();i++)
	{
		int x=e[i].x,y=e[i].y;
		LL w=e[i].w;
		int fx=find(x),fy=find(y);
		if (fx!=fy)
		{
			fa[fx]=fy;
			ans+=w;
			if (x==0||y==0) nn.pb(x+y);
			else way.pb(mp(x,y));
		}
	}
	cout<<ans<<endl;
	cout<<nn.size()<<endl;
	for (int i=0;i<nn.size();i++)
	{
		if (i!=0) cout<<" ";
		cout<<nn[i];
	}
	cout<<endl;
	cout<<way.size()<<endl;
	for (int i=0;i<way.size();i++)
		cout<<way[i].fi<<" "<<way[i].se<<endl;
	return 0;
}