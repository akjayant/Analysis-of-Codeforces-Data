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

const ll MOD = 1e9 + 7;

ll bin_exp(ll b, ll e, ll mod = MOD) {
	ll ret = 1;
	while (e > 0) {
		if (e & 1) {
			(ret *= b) %= mod;
		}
		(b *= b) %= mod;
		e >>= 1;
	}
	return ret;
}

void func() {
	ll n, m; cin >> n >> m;
	cout << bin_exp(bin_exp(2, m) - 1, n) << endl;
}

int main() {
    fast_io;
    int t = 1; // cin >> t;
    for (int i = 0; i < t; ++i) {
        func();
    }
}