#pragma GCC optimize ("-O3")
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
ll NUM = 1e9+7;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define zer ll(0)

ll fn(v64 ord, v64 c1, v64 c2, v64 c3)
{
	ll ans = 0;
	forn(i, ord.size())
	{
		if(i%3 == 0)
		{
			ans += c1[ord[i]];
		}
		else if(i%3 == 1)
		{
			ans += c2[ord[i]];	
		}
		else
		{
			ans += c3[ord[i]];
		}
	}
	return ans;
}

int main()
{
    fast_cin();
    ll n;
    cin>>n;
    v64 c1(n),c2(n),c3(n);
    forn(i, n)
    {
    	cin>>c1[i];
    }
    forn(i, n)
    {
    	cin>>c2[i];
    }
    forn(i, n)
    {
    	cin>>c3[i];
    }
    vv64 tr(n);
    v64 deg(n, 0);
    ll u,v;
    forn(i, n-1)
    {
    	cin>>u>>v;
    	u--;
    	v--;
    	tr[u].pb(v);
    	tr[v].pb(u);
    	deg[u]++;
    	deg[v]++;
    }
    bool flg = 1;
    ll leaf = -1;
    forn(i, n)
    {
    	if(deg[i] > 2)
    	{
    		flg = 0;
    	}
    	if(deg[i] == 1)
    	{
    		leaf = i;
    	}
    }
    if(flg)
    {
    	v64 ord(n, -1);
    	ord[0] = leaf;
    	ll i = 1;
    	ll curr = tr[leaf][0];
    	while(true)
    	{
    		ord[i] = curr;
    		if(deg[curr] == 1)
    		{
    			break;
    		}
    		else
    		{
    			if(tr[curr][0] != ord[i-1])
    			{
    				curr = tr[curr][0];
    			}
    			else
    			{
    				curr = tr[curr][1];
    			}
    		}
    		i++;
    	}
    	ll out = INF;
    	ll v1,v2,v3;
    	ll tmp;
    	tmp = fn(ord, c1, c2, c3);
    	if(tmp < out)
    	{
    		out = tmp;
    		v1 = 1;
    		v2 = 2;
    		v3 = 3;
    	}
    	tmp = fn(ord, c1, c3, c2);
    	if(tmp < out)
    	{
    		out = tmp;
    		v1 = 1;
    		v2 = 3;
    		v3 = 2;
    	}
    	tmp = fn(ord, c2, c1, c3);
    	if(tmp < out)
    	{
    		out = tmp;
    		v1 = 2;
    		v2 = 1;
    		v3 = 3;
    	}
    	tmp = fn(ord, c2, c3, c1);
    	if(tmp < out)
    	{
    		out = tmp;
    		v1 = 2;
    		v2 = 3;
    		v3 = 1;
    	}
    	tmp = fn(ord, c3, c1, c2);
    	if(tmp < out)
    	{
    		out = tmp;
    		v1 = 3;
    		v2 = 1;
    		v3 = 2;
    	}
    	tmp = fn(ord, c3, c2, c1);
    	if(tmp < out)
    	{
    		out = tmp;
    		v1 = 3;
    		v2 = 2;
    		v3 = 1;
    	}
    	cout<<out<<'\n';
    	v64 ot(n);
    	forn(i, n)
    	{
    		if(i%3 == 0)
    		{
    			ot[ord[i]] = v1;
    		}
    		if(i%3 == 1)
    		{
    			ot[ord[i]] = v2;
    		}
    		if(i%3 == 2)
    		{
    			ot[ord[i]] = v3;
    		}
    	}
    	forn(i, n)
    	{
    		cout<<ot[i]<<" ";
    	}
    }
    else
    {
    	cout<<-1<<'\n';
    }
    return 0;
}
