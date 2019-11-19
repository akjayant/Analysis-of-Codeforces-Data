#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ii pair <int, int>
#define MP make_pair
#define F first
#define S second
#define L(x) ((x << 1) + 1)
#define R(x) ((x << 1) + 2)
#define mid(l, r) (l + r >> 1)
#define PB push_back
#define trace(x) cerr << #x << " = " << x << endl;
#define int long long

signed main() {
	fast_io;

	int n;

	cin >> n;

	if (n == 2) {
		cout << 2 << endl;
		return 0;
	}

	int SQRT = sqrt(n);

	int ans = n;
	for (int i=2 ; i<=SQRT + 1 ; ++i) {
		if ((n % i) == 0) {
			ans = __gcd(ans, i);
			ans = __gcd(ans, n/i);
		}
	}

	cout << ans << endl;
}