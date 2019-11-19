#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--) 
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ordered_set tree<ll int, null_type,less<ll int>, rb_tree_tag,tree_order_statistics_node_update> 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll int t;
	cin >> t;
	// ll int u=0;
	while(t--)
	{
		ll int n;
		cin >> n;
		ll int e=0;
		ll int o=0;
		rep(i,0,n)
		{
			ll int value;cin >> value;
			if (value%2)e=e+1;
			else o=o+1;
		}
		ll int m;
		cin >> m;
		ll int e1=0;
		ll int o1=0;
		rep(i,0,m)
		{
			ll int value;
			cin >> value;
			if (value%2) e1=e1+1;
			else o1=o1+1;
		}
		cout << e*e1+o*o1 << endl;
	}
}