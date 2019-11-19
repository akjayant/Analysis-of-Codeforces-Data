#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>

void solve() {
	int n;
	cin >> n;
	ll k;
	cin >> k;
	vi a;
	a.resize(n);
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	int i = 0, j = a.size() - 1;
	ll L = a[0], R = a[a.size() - 1];
	ll l = mp[a[i]], r = mp[a[j]];
	while (k > 0 && i < j) {
		//cout << i << ' ' << j << endl;
		//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << r << endl;
		if (l < r) {
			ll shift = abs(a[i] - a[i + 1]) * l;
			if (shift > k) {
				shift = k / l;
			} else {
				shift = abs(a[i] - a[i + 1]);
			}
			//cout << shift << endl;
			if (shift * l == 0)
				break;
			k -= shift * l;
			L += shift;
			++i;
			l += mp[a[i]];
		} else {
			ll shift = abs(a[j] - a[j - 1]) * r;
			if (shift > k) {
				shift = k / r;
			} else {
				shift = abs(a[j] - a[j - 1]);
			}
			if (shift * r == 0)
				break;
			k -= shift * r;
			R -= shift;
			j--;
			r += mp[a[j]];
		}
	}
	cout << abs(L - R) << endl;
}

signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}	
}