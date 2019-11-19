#include<bits/stdc++.h>
typedef long long ll;
ll mod =1000000007;
using namespace std;
int n;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll x[2003];
ll y[2003];
ll c[2003];
ll k[2003];

int par[2003];

int findpar(int x)
{
	if(par[x]==-1)
	{
		return x;
	}
	return par[x]=findpar(par[x]);
}

struct node{

ll cost;
int x,y;
};

bool cmp(node xx,node yy)
{
	return xx.cost<yy.cost;
}
int main()
{
	int i,j,fl,test;
	ll ans=0;
	scanf("%d",&n);
	vector<pair<int,int> > fed;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&c[i]);
		//ans=ans+c[i];
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
	}
	vector<node> edges;
	memset(par,-1,sizeof(par));

	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			ll cp=(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
			node tmp;
			tmp.cost=cp;
			tmp.x=i;
			tmp.y=j;
			edges.push_back(tmp);

		}
	}
	for(i=1;i<=n;i++)
	{
			ll cp=c[i];
			node tmp;
			tmp.cost=cp;
			tmp.x=i;
			tmp.y=n+1;
			edges.push_back(tmp);
	}
	sort(edges.begin(),edges.end(),cmp);

	vector<int> powerst;
	for(i=0;i<edges.size();i++)
	{
		int s=edges[i].x;
		int t=edges[i].y;
		ll cost=edges[i].cost;
		int ps=findpar(s);
		int pt=findpar(t);
		if(ps==pt)
			continue;
		par[ps]=pt;
		ans=ans+cost;
		if(t==n+1)
			powerst.push_back(s);
		else
			fed.push_back(make_pair(s,t));
	
	}
	printf("%lld\n",ans );
	printf("%d\n",powerst.size() );
	for(i=0;i<powerst.size();i++)
	{
		printf("%d ",powerst[i] );
	}
	printf("\n");
	printf("%d\n",fed.size() );
	for(i=0;i<fed.size();i++)
	{
		printf("%d %d\n",fed[i].first,fed[i].second );
	}

	return 0;
}