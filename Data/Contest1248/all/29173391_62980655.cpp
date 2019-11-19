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
	ll int t=1;
	//cin >> t;
	// ll int u=0;
	while(t--)
	{
		ll int n;
		cin >> n;
		ll int a[n];
		ll int sum1=0;
		rep(i,0,n) {cin >> a[i];sum1=sum1+a[i];}
		sort(a,a+n);
		ll int sum2=0;
		rep(i,0,n/2)
		{
			sum2=sum2+a[i];
		}
		cout << (sum1-sum2)*(sum1-sum2)+sum2*sum2 << endl;
	}
}