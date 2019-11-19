#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int                 long long
#define ll                  long long
#define ld                  long double
#define rep(i,n)            for(int i=0;i<n;i++)
#define hell                1000000007
#define inf                 (ll)1e15
#define vi                  vector<int>
#define vii                 vector< vi >
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pii                 pair<int,int>
#define all(c)              c.begin(),c.end()
#define sz(c)               (int)c.size()
#define hash1               105727LL
#define hash2               hell
//#define endl                '\n'
#define eps                 1e-10
#define pi                  3.141592653589793238462643383279502884197
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,
				rb_tree_tag,tree_order_statistics_node_update> statisticsTree;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll x, ll y,ll p)
{
	ll res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)
			res=((res%p)*(x%p))%p;
		y=y>>1;
		x=((x%p)*(x%p))%p;
	}
	return res;
}
ll raichu(ll x,ll y)
{
	ll res=1;
	while(y>0)
	{
		if(y&1)
			res=((res)*(x));
		y=y>>1;
		x=((x)*(x));
	}
	return res;
}
bool isprime(ll n)
{
	if(n<2) return false;
	else if(n==2) return true;
	else if(n%2==0) return false;
	else
	{
		ll z=sqrt(n);
		rep(i,z-1) if(n%(i+2)==0) return false;
		return true;
	}
}
vector<int> A;
void dfs(int c,int p,vii &g,vii &C)
{
	int cnt=0;
	vector<int> childs;
	for(auto i:g[c])
	{
		if(i!=p)
		{
			cnt++;
			if(cnt>2) break;
			childs.pb(i);
		}
	}
	if(cnt>2)
	{
		cout<<-1;
		exit(0);
	}
	if(c!=p && cnt>1)
	{
		cout<<-1;
		exit(0);
	}
	for(auto i:childs)
	{
		dfs(i,c,g,C);
	}
}
void dfs1(int c,int p,vii &g)
{
	A.pb(c);
	for(auto i:g[c])
	{
		if(i!=p)
		{
			dfs1(i,c,g);
		}
	}
}
int32_t main()
{
	//freopen("B-large.in","r",stdin);
	//freopen("out2.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tests=1,Tests;
	//cin>>tests;
	Tests=tests;
	while(tests--)
	{
		int n;
		cin>>n;
		vector<vector<int> > C(3,vector<int>(n));
		rep(i,3)
		{
			rep(j,n)
			{
				cin>>C[i][j];
			}
		}
		vii g(n);
		rep(i,n-1)
		{
			int u,v;
			cin>>u>>v;
			g[--u].pb(--v);
			g[v].pb(u);
		}
		dfs(0,0,g,C);
		int st=0;
		rep(i,n)
		{
			if(sz(g[i])==1) st=i;
		}
		//cout<<st+1<<endl;
		dfs1(st,st,g);
		ll dp[n+1][3][3];
		memset(dp,0,sizeof dp);
		ll prev[n+1][3][3];
		memset(prev,-1,sizeof prev);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=2;j++)
			{
				for(int k=0;k<=2;k++)
				{
					if(j==k) continue;
					//dp[i][j][k]
					for(int p=0;p<=2;p++)
					{
						if(p!=j && p!=k)
						{
							dp[i][j][k]=max(dp[i-1][p][j]+C[p][A[i-1]],dp[i][j][k]);
							if(dp[i][j][k]==dp[i-1][p][j]+C[p][A[i-1]])
							{
								prev[i][j][k]=p;
							}
						}
					}
				}
			}
		}
		int bi,bj;
		ll ma=LLONG_MAX;
		for(int i=0;i<=2;i++)
		{
			for(int j=0;j<=2;j++)
			{
				if(i!=j)
				{
					if(dp[n][i][j]<ma)
					{
						ma=dp[n][i][j];
						bi=i;
						bj=j;
					}
				}
			}
		}
		//cout<<bi<<" "<<bj<<endl;
		cout<<ma<<endl;
		vector<ll> ans(n,0);
		int idx=n;
		while(idx>0)
		{
			ans[A[idx-1]]=prev[idx][bi][bj];
			int z=ans[A[idx-1]];
			bj=bi;
			bi=z;
			idx--;
		}
		rep(i,n) cout<<ans[i]+1<<" ";
	}
	return 0;
}