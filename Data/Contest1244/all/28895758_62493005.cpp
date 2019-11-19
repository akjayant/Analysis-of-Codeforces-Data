#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;

ll n,cl[6][100005],pc[100005],chcl[100005],anw=1e15,ed,st,go; //i n
vector<ll> g[100005];

void dfs(ll a,ll p)
{
	for(int i=0;i<g[a].size();i++)
		if(g[a][i]!=p)
			dfs(g[a][i],a),pc[a]=g[a][i];
	if(g[a].size()>=3)
	{
		cout<<-1;
		exit(0);	
	}	
	if(g[a].size()==1&&p!=-1)
		ed=a;
}

void getanw(ll a,ll p,ll lc,ll llc,ll sum)
{
	ll tk=0;
	for(int i=1;i<=3;i++)
		if(i!=lc&&i!=llc)
			sum+=cl[i][a],tk=i;
	if(a==ed)
	{
		if(anw>sum)
		{
			anw=sum;
			go=1;
		}
		return;
	}
	for(int i=0;i<g[a].size();i++)
		if(g[a][i]!=p)
			getanw(g[a][i],a,tk,lc,sum);
}

void fill(ll a,ll p,ll lc,ll llc)
{
	ll tk=0;
	for(int i=1;i<=3;i++)
		if(i!=lc&&i!=llc)
			tk=i,chcl[a]=i;
	if(a==ed)
	{
		return;
	}
	for(int i=0;i<g[a].size();i++)
		if(g[a][i]!=p)
			fill(g[a][i],a,tk,lc);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
			cin>>cl[i][j];
	for(int i=1;i<n;i++)
	{
		ll a,b;cin>>a>>b;
		g[a].push_back(b),g[b].push_back(a);
	}
	for(int i=1;i<=n;i++)
		if(g[i].size()==1)
		{
			st=i;
			break;
		}
	dfs(st,-1);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			if(i==j) continue;
			getanw(pc[pc[st]],pc[st],j,i,cl[i][st]+cl[j][pc[st]]);
			if(go)
			{
				go=0;	
				chcl[pc[st]]=j,chcl[st]=i;
				fill(pc[pc[st]],pc[st],j,i);
			}
		}
	cout<<anw<<"\n";
	for(int i=1;i<=n;i++)
		cout<<chcl[i]<<" ";
	return 0;
}