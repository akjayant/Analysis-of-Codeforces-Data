#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define X first
#define Y second
#define sz(v) (int)v.size()

void solve();

main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	freopen("in.txt", "r", stdin);
#endif
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}



void solve() {
	ll n;
	cin >> n;
	ll ans = n;
	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			ans = __gcd(ans, i);
			while (n % i == 0) n /= i;
		}
	}
	if (n != 1) ans = __gcd(ans, n);
	cout << ans;
}