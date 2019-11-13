#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k, n, a[1010];

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>k;

	while(k--) {

		cin>>n;
		for(ll i=0;i<n;i++) cin>>a[i];

		sort(a, a+n, cmp);

		ll ans = 0;

		for(ll i=0;i<n;i++) {
			ans = max(ans, min(i+1, a[i]));
		}

		cout<<ans<<endl;

	}

}