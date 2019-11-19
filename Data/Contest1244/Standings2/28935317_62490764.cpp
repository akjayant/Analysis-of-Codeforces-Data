#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define test() int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define nl cout<<"\n"

const int MAXN = 1005;
const int LOGN = 20;
const ll INF = 1e14;

int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll>a(n),cum(n+1);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());

	for(int i=0;i<n;i++)
	{
		cum[i+1] = cum[i] + a[i];
	}

	ll ans = INF;
	for(int i=0;i<n;i++)
	{
		ll lo=0,hi=1e10,mid,tans=1e10;
		ll mini = a[i], maxi;
		while( lo <= hi )
		{
			mid = lo + (hi-lo)/2;

			maxi = mini + mid;

			int ub = upper_bound(a.begin(),a.end(),maxi) - a.begin();
			ll up = (cum[n] - cum[ub]) - (n-ub)*maxi;

			int lb = lower_bound(a.begin(),a.end(),mini) - a.begin();
			ll down = lb*mini - cum[lb];

			// cout<<mid<<" "<<up<<" "<<down,nl;

			if( up + down <= k )
			{
				hi = mid-1;
				tans = mid;
			}
			else 
				lo = mid+1;
		}
		// cout<<a[i]<<" "<<tans,nl;
		ans = min(ans, tans);


		lo=0,hi=a[i],tans=1e10;
		maxi = a[i];
		while( lo <= hi )
		{
			mid = lo + (hi-lo)/2;

			mini = maxi - mid;

			int ub = upper_bound(a.begin(),a.end(),maxi) - a.begin();
			ll up = (cum[n] - cum[ub]) - (n-ub)*maxi;

			int lb = lower_bound(a.begin(),a.end(),mini) - a.begin();
			ll down = lb*mini - cum[lb];

			// cout<<mid<<" "<<up<<" "<<down,nl;

			if( up + down <= k )
			{
				hi = mid-1;
				tans = mid;
			}
			else 
				lo = mid+1;
		}
		ans = min(ans, tans);
	}
	cout<<ans,nl;

	return 0;
}