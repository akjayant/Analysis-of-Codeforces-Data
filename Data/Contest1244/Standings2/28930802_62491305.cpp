#include <bits/stdc++.h>
using namespace std;
 
#define M 1000000007
 
#define mp make_pair
#define pb push_back
#define tri pair<int, pair<int, int> >
#define TRI(a,b,c) (make_pair(a,make_pair(b,c)))
 
typedef long long ll;
typedef long double ld;

ll powmod(ll x, ll y, ll m=M)
{
	if(y==0) return 1;
	ll ret = powmod(x, y/2, m);
	ret = (ret*ret)%m;
	if(y%2) ret=(ret*x)%m;
	return ret;
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin>>n;
    ll cost[n+1][3];
    for(int j=0; j<3; j++)
    {
    	for(int i=1; i<=n; i++)
    	{
    		cin>>cost[i][j];
    	}
    }
    vector<ll> adj[n+1];
    for(int i=1; i<n; i++)
    {
    	int u, v; cin>>u>>v;
    	adj[u].pb(v); adj[v].pb(u);
    	if(adj[u].size() > 2 || adj[v].size() > 2)
    	{
    		cout<<-1;
    		return 0;
    	}
    }
    ll st = 0, en = 0, ans = -1, ans1 = 0;
    for(int i=1; i<=n; i++)
    {
    	if(adj[i].size() == 1)
    	{
    		if(st==0) st = i;
    		else en = i;
    	}
    }
    vector<ll> vec;
    ll nd = -1, prev;
    while(nd!=en)
	{
		if(nd == -1)
		{
			prev = nd;
			nd = st;
		}
		else
		{
			if(adj[nd][0] != prev)
			{
				prev = nd;
				nd = adj[nd][0];
			}
			else
			{
				prev = nd;
				nd = adj[nd][1];
			}
		}
		vec.pb(nd);
	}
    for(int j = 0; j<6; j++)
    {
    	ll cnt = 0;
    	ll c[3] = {0, 0, 0};
    	c[0] = j/2;
    	if(c[0] == 0)
    	{
    		if(j%2)
    		{
    			c[1] = 2; c[2] = 1;
    		}
    		else
    		{
    			c[1] = 1; c[2] = 2;
    		}
    	}
    	else if(c[0] == 1)
    	{
    		if(j%2)
    		{
    			c[1] = 2; c[2] = 0;
    		}
    		else
    		{
    			c[1] = 0; c[2] = 2;
    		}
    	}
    	else
    	{
    		if(j%2)
    		{
    			c[1] = 1; c[2] = 0;
    		}
    		else
    		{
    			c[1] = 0; c[2] = 1;
    		}
    	}
    	ll curr = 0;
    	for(int i=0; i<n; i++)
    	{
    		curr += cost[vec[i]][c[i%3]];
    	}
    	if(ans == -1) ans = curr;
    	else if(ans > curr)
    	{
    		ans = curr;
    		ans1 = j;
    	}
    }
    cout<<ans<<"\n";
    ll c[3] = {0, 0, 0};
	c[0] = ans1/2;
	if(c[0] == 0)
	{
		if(ans1%2)
		{
			c[1] = 2; c[2] = 1;
		}
		else
		{
			c[1] = 1; c[2] = 2;
		}
	}
	else if(c[0] == 1)
	{
		if(ans1%2)
		{
			c[1] = 2; c[2] = 0;
		}
		else
		{
			c[1] = 0; c[2] = 2;
		}
	}
	else
	{
		if(ans1%2)
		{
			c[1] = 1; c[2] = 0;
		}
		else
		{
			c[1] = 0; c[2] = 1;
		}
	}
	vector<ll> vec2(n);
	for(int i=0; i<n; i++)
	{
		vec2[vec[i]-1] = c[i%3]+1;
	}
	for(int i=0; i<n; i++)
	{
		cout<<vec2[i]<<" ";
	}
    return 0;
}