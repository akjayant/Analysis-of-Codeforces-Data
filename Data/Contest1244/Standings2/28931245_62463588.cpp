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
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;
	int lol = ((a + c - 1) / c) + (b + d - 1) / d;
	if (lol > k) {
		cout << -1 << endl;
	} else {
		cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << endl;
	}
}

signed main() {
	int t;
	t = 1;
	cin >> t;
	while (t--) {
		solve();
	}	
}