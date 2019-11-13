#include<bits/stdc++.h>
typedef  long long int ll;
typedef  long double ld;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;
ll modexp(ll a,ll b)
{
	a%=mod;
	if(a==0||a==1)
	return a;
	if(b==0)
	return 1;
	if(b%2==0)
	{
		ll res=modexp(a,b/2);
		return (res*res)%mod;
	}
	return (a*modexp(a,b-1))%mod;
}
int main()
{
	sync;
	ll n,m;
	cin>>n>>m;
	ll ans=(modexp(2,m)-1+mod)%mod;
	ans=modexp(ans,n);
	cout<<ans;
}