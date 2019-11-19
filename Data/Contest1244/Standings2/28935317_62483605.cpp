#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define test() int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define nl cout<<"\n"

const int MAXN = 100005;
const int LOGN = 20;
const ll INF = 1e18;

vector<int>gr[MAXN];
ll col[MAXN][3];
int colors[MAXN];

ll dfs( int node, int par, int fir, int sec, int step )
{
	ll ans = 0;
	if( step == 0 )
		ans = col[node][fir];
	else if( step == 1 )
		ans = col[node][sec];
	else
		ans = col[node][3-fir-sec];
	for( auto next : gr[node] )
	{
		if( next != par )
		{
			ans += dfs(next,node,fir,sec,(step+1)%3);
		}
	}
	return ans;
}

void color( int node, int par, int f, int s, int step )
{
	if( step == 0 )
		colors[node] = f;
	else if( step == 1 )
		colors[node] = s;
	else
		colors[node] = 3-f-s;
	for( auto next : gr[node] )
	{
		if( next != par )
		{
			color(next,node,f,s,(step+1)%3);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<n;i++)
		{
			cin>>col[i][j];
		}
	}

	bool f = 0;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		u--,v--;
		gr[u].pb(v);
		gr[v].pb(u);
		if( gr[u].size() > 2 || gr[v].size() > 2 )
		{
			f = 1;
		}
	}
	if( f )
	{
		cout<<-1;
		return 0;
	}

	int rem = -1;
	for(int i=0;i<n;i++)
	{
		if( gr[i].size() == 1 )
		{
			rem = i;
			break;
		}
	}

	ll ans = INF;
	int fi = -1, si = -1;
	for(int col=0;col<3;col++)
	{
		for(int sec=0;sec<3;sec++)
		{
			if( sec == col ) continue;
			ll store = dfs(rem,-1,col,sec,0);
			if( store < ans )
			{
				ans = store;
				fi = col, si = sec;
			}
		}
	}
	cout<<ans,nl;
	color(rem,-1,fi,si,0);
	for(int i=0;i<n;i++)
		cout<<colors[i]+1<<" ";

	return 0;
}