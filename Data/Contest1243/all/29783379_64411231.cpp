#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;	

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define test() ll t;cin>>t;for(ll test = 1;test<=t;test++)
#define f first
#define s second
#define pb push_back
#define nl cout<<"\n"
#define MOD(x) ((x%P)+P)%P
#define vec(v) loop(i,0,v.size()) cout<<v[i]<<" "; nl
const int N = 100005;
const ll P = 1000000007;
const double eps = 1e-6;

int par[N], sz[N];

int root(int x)
{
	while(x!=par[x])
	{
		par[x] = par[par[x]];
		x = par[x];
	}
	return x;
} 

void join(int x, int y)
{
	int p1 = root(x);
	int p2 = root(y);
	if(p1==p2)
		return;
	if(sz[p1]>=sz[p2])
	{
		par[p2] = p1;
		sz[p1] += sz[p2];
	}
	else
	{
		par[p1] = p2;
		sz[p2] += sz[p1];
	}	
}


int main()
{
	fastio();
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m; cin>>n>>m;

	for(int i=0; i<=n; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}

	vector<int> gr[n+1];
	for(int i=0; i<m; i++)
	{
		int u,v; cin>>u>>v;
		gr[u].pb(v);
		gr[v].pb(u);
	}

	vector<int> one;
	for(int i=1; i<=n; i++)
	{
		int deg = n-1-gr[i].size();

		if(deg>=((n+1)/2))
			one.pb(i);
		else
		{
			sort(gr[i].begin(), gr[i].end());
			gr[i].pb(n+1);
			int now = 1;
			int it = 0;
			while(now<=n)
			{
				if(gr[i][it]==now)
					it++;
				else
					join(i,now);
				now++;
			}
		}
	}

	if(one.size())
	{
		for(int i=0; i<one.size(); i++)
			join(one[i], one[0]);
	}
	set<int> st;
	for(int i=1; i<=n; i++)
		st.insert(root(i));

	cout<<st.size()-1,nl;




	cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
	return 0;
}