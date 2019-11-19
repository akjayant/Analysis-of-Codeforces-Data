#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pb push_back
#define endl '\n'
#define PI acos(-1)
#define bitcount(a) __builtin_popcountll(a)
#define P pair<int,int>
#define ff first
#define ss second
typedef tree<int,null_type,less_equal <int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
long double eps=1e-9;
int mod=1e9+7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int m;
		cin>>m;
		int b[m];
		int odd=0,even=0;
		for(int i=0;i<m;i++)
		{
			cin>>b[i];
			if(b[i]&1) ++odd;
			else ++even;
		}	
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]&1) ans+=odd;
			else ans+=even;
		}
		cout<<ans<<endl;

	}
	return 0;
}