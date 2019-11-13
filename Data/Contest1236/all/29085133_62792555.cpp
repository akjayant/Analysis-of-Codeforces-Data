#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int,int>
#define pl pair<long long,long long>
#define rep(i,xi,yi,zi) for(ll i=xi;i<yi;i+=zi)
#define repe(i,xi,yi,zi) for(ll i=xi;i<=yi;i+=zi)
#define rrep(i,xi,yi,zi) for(ll i=xi;i>=yi;i-=zi)
#define pq priority_queue<long long>
#define rpq priority_queue<long long, vector<long long>, greater<long long> >
#define umap tr1::unordered_map
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
using namespace __gnu_pbds; 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pset; 

ll calpow(ll a,ll b)
{
	ll x=1;
	while(b>0)
	{
		if(b&1)x=(x%mod*a%mod)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return x;
}

int main()
{
	fastIO
	ll n,m;cin>>n>>m;
	ll ans=(calpow(2,m)-1+mod)%mod;
	ans=calpow(ans,n);
	cout<<ans;
	return 0;
} 