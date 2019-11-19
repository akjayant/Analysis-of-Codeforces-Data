#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double


signed main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		if (ceil((long double)a / c) + ceil((long double)b / d) > k) cout << -1 << endl;
		else cout << ceil((long double)a / c) << " " << ceil((long double)b / d) << endl;
	}
}