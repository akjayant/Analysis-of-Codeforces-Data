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
int main()
{
	sync;	
	ll n;
	cin>>n;
	ll arr[n];
	input(arr,n);
	sort(arr,arr+n);
	ll sumx=0,sumy=0;
	for(ll i=0;i<n;i++)
	{
		if(i<n/2)
		sumx+=arr[i];
		else
		sumy+=arr[i];
	}
	cout<<sumx*sumx+sumy*sumy;
}