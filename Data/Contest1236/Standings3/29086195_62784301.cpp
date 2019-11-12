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
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	while (b >= 1 and c >= 2) {
		ans += 3;
		b--; c -= 2;
	}
	while (a >= 1 and b >= 2) {
		ans += 3;
		a--; b -= 2;
	}
	cout << ans << endl;
}

int main() {
    fast_io;
    int t = 1; cin >> t;
    for (int i = 0; i < t; ++i) {
        func();
    }
}