#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 9223372036854775807
#define mini 9223372036854775807
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
pair<ll,ll>s4[4]={{-1,0},{1,0},{0,-1},{0,1}};
pair<ll,ll>s8[8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,1},{1,0},{1,-1}};
ll power(ll a,ll b)
{
	if(b==0)
		return 1;
	ll c=power(a,b/2);
	if(b%2==0)
		return ((c%mod)*(c%mod))%mod;
	else
		return ((((c%mod)*(c%mod))%mod)*a)%mod;
}
ll dp[105][105][105];
ll func(ll a,ll b,ll c)
{
	if(dp[a][b][c]!=-1)
		return dp[a][b][c];
	ll ans=0;
	if(a>=1 && b>=2)
		ans=max(ans,3+func(a-1,b-2,c));
	if(b>=1 && c>=2)
		ans=max(ans,3+func(a,b-1,c-2));
	return dp[a][b][c]=ans;
}
int main()
{
	boost
	ll t,i;
	cin>>t;
	for(i=0; i<t; i++)
	{
		memset(dp,-1,sizeof(dp));
		ll a,b,c;
		cin>>a>>b>>c;
		cout<<func(a,b,c)<<endl;
	}
	return 0;
}