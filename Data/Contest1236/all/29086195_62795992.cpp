// Author: Vamsi Krishna Reddy Satti
// With love for Competitive Programming!
 
#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define cout_precision cout.setf(ios::fixed); cout.precision(32);
 
using ll = int64_t; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
using vll = vector<ll>;

// -----------------------------------------------------------------------------

void func() {
	ll n; cin >> n;
	ll ans[n][n];
	for (int i = 0, p = 0, x = 1; i < n; i++, p ^= 1) {
		if (p == 0) {
			for (int j = 0; j < n; j++) {
				ans[j][i] = x++;
			}
		} else {
			for (int j = n - 1; j >= 0; j--) {
				ans[j][i] = x++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
    fast_io;
    int t = 1; // cin >> t;
    for (int i = 0; i < t; ++i) {
        func();
    }
}