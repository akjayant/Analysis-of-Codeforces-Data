#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define M 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n,a[3][100005],r[100005];
vl adj[100005],v;
void dfs(ll i,ll par=0)
{
	v.pb(i);
	for(auto j:adj[i])
	{
		if(j!=par)
			dfs(j,i);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rep(i,0,3)
    {
    	rep(j,1,n+1)
    		cin>>a[i][j];
    }
    rep(i,0,n-1)
    {
    	ll u,v;
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    ll s=-1;
    rep(i,1,n+1)
    {
    	if(sz(adj[i])>=3)
    	{
    		cout<<-1<<"\n";
    		return 0;
    	}
    	if(sz(adj[i])==1)
    		s=i;
    }
    dfs(s);
    vl g={0,1,2},ans1;
    ll ans=LLONG_MAX;
    do
    {
    	ll temp=0;
    	rep(i,0,n)
    		temp+=a[g[i%3]][v[i]];
    	if(ans>temp)
    	{
    		ans=temp;
    		ans1=g;
    	}
    }
    while(next_permutation(all(g)));
    cout<<ans<<"\n";
    rep(i,0,n)
    	r[v[i]]=ans1[i%3];
    rep(i,1,n+1)
    	cout<<r[i]+1<<" ";
}
