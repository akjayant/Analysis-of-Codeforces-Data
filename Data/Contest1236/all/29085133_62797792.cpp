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

int main()
{
	fastIO
	ll n;cin>>n;
	ll a[n][n];ll x=0,cnt=1;
	rep(i,0,n,1)
	{
		if(!x)
		{
			x=1;
			rep(j,0,n,1)a[j][i]=cnt,cnt+=1;
		}
		else
		{
			x=0;
			rrep(j,n-1,0,1)a[j][i]=cnt,cnt+=1;
		}
	}
	rep(i,0,n,1){rep(j,0,n,1)cout<<a[i][j]<<" ";cout<<"\n";}
	return 0;
} 