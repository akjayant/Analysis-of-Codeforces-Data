#include <bits/stdc++.h>
#define fs first
#define sc second
#define mx 100005
#define mod 1000000007
#define pii pair<int, int>
#define ll long long
#define mkp make_pair
#define all(a) a.begin(),a.end()
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	ll k;
	scanf("%lld", &k);
	ll a[n+1];
	ll cum[n+1];
	a[n] = INT_MAX;
	for(int i = 0; i<n; i++)
		scanf("%lld", &a[i]);
	sort(a, a+n);
	cum[n-1] = a[n-1];
	for(int i = n-2; i>=0; i--)
		cum[i] = cum[i+1] + a[i];
	cum[n] = 0;
	ll ans = (1ll << 60);
	ll sum = 0;

	// for(int i = 0; i<=n; i++)
	// 	cout << a[i] << " ";
	// cout << endl;
	// for(int i = 0; i<=n; i++)
	// 	cout << cum[i] << " ";
	// cout << endl;
		// cout << cum[0]-(n-0)*a[0] << endl;
	for(int i = 0; i<n; i++){
		sum = 1ll * (i+1) * a[i] - (cum[0] - cum[i+1]);
		ll nwk = k-sum;
		// cout << sum << " - " << nwk << endl;
		if(nwk < 0) break;
		int l = i, r = n-1; 
		while(l <= r){
			int mid = (l + r)/2;
			if(cum[mid]-1ll*(n-mid)*a[mid] <= nwk) r = mid-1;
			else l = mid + 1;
		}
		r++;
		// cout << i << " " << r << " " << cum[r] - (n-r)*a[r] << endl;
		if(r < n){
			ll baki = nwk - (cum[r] - 1ll*(n-r)*a[r]);
			// cout << i << " " << r << " " << baki << endl;
			ans = min(ans, max(0ll, a[r] - min(i<n-1?a[i+1]-a[i]:INT_MAX, baki/(i+1)) - a[i]));
			ans = min(ans, max(0ll, a[r] - min(r?a[r]-a[r-1]:INT_MAX, baki/(n-r)) - a[i]));
		}
	}

	for(int i = n-1; i>=0; i--){
		sum = cum[i] - 1ll*(n-i) * a[i];
		ll nwk = k-sum;
		// cout << sum << " - " << nwk << endl;
		if(nwk < 0) break;
		int l = 0, r = i; 
		while(l <= r){
			int mid = (l + r)/2;
			if((mid+1)*a[mid] - (cum[0] - cum[mid+1]) <= nwk) l = mid+1;
			else r = mid - 1;
		}
		l--;
		r = l;
		// cout << i << " " << r << " " << cum[r] - (n-r)*a[r] << endl;
		if(r < n){
			ll baki = nwk - ((r+1)*a[r] - (cum[0] - cum[r+1]));
			// cout << i << " " << r << " " << baki << endl;
			swap(i, r);
			ans = min(ans, max(0ll, a[r] - min(i<n-1?a[i+1]-a[i]:INT_MAX, baki/(i+1)) - a[i]));
			ans = min(ans, max(0ll, a[r] - min(r?a[r]-a[r-1]:INT_MAX, baki/(n-r)) - a[i]));
			swap(i, r);
		}
	}
	printf("%lld\n", ans);
	return 0;
}