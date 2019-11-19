#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<string>
using namespace std;
typedef long long ll;
#define pb push_back
#define mk make_pair
#define rep(a,b,c) for(int a=b;a<c;a++)
#define repp(a,b,c) for(int a=b;a<=c;a++)
#define mem(a,b) memset(a,b,sizeof(a))
const int inf=0x3f3f3f3f;
const int maxn=2005;

void useiostream()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
struct city
{
	ll x,y;
}ci[maxn];
int root[maxn];
ll cj(int a,int b)
{
	return abs(ci[a].x-ci[b].x)+abs(ci[a].y-ci[b].y);
}
struct edge
{
	int u,v;
	ll w;
	int nex;
	edge(){}
	edge(int a,int b,ll c)
	{
		u=a;
		v=b;
		w=c;
	}
}e[maxn*maxn];
int head[maxn];
int cnt=0;
void init()
{
	cnt=0;
	for(int i=0;i<=maxn;i++)root[i]=i;
	mem(head,-1);
}
void add(int a,int b,ll c)
{
	e[cnt].u=a;
	e[cnt].v=b;
	e[cnt].w=c;
	e[cnt].nex=head[a];
	head[a]=cnt++;
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int find(int num)
{
	if(num==root[num])return root[num];
	else
	{
		root[num]=find(root[num]);
		return root[num];
	}
}
ll val[maxn];
ll ans=0;
vector<int>vis;
vector<pair<int,int> >evis;
void kru()
{
	sort(e,e+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		int u=e[i].u;
		int v=e[i].v;
		ll w=e[i].w;
		int x=find(u);
		int y=find(v);
		if(x==y)continue;
		root[y]=x;
		ans+=w;
		if(u==0||v==0)
		{
			vis.pb(max(u,v));
		}
		else
		{
			evis.pb(mk(u,v));
		}
	}
}
int main()
{
	init();
	int n;
	cin>>n;
	repp(i,1,n)
	{
		cin>>ci[i].x>>ci[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		add(0,i,a);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ll lins=cj(i,j)*(val[i]+val[j]);
			add(i,j,lins);
		}
	}
	kru();
	cout<<ans<<endl;
	cout<<vis.size()<<endl;
	for(int i=0;i<vis.size();i++)
	{
		cout<<vis[i]<<" ";
	}
	cout<<endl;
	cout<<evis.size()<<endl;
	for(int i=0;i<evis.size();i++)
	{
		cout<<evis[i].first<<" "<<evis[i].second<<endl;
	}
}