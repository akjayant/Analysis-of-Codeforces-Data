#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

ll ar[1000010];

int main () {
	// freopen ("input.txt", "r", stdin);
	ll t, n, i, ans, a, b, c, max_a, max_c, max_b;
	cin >> t;
	// t = 1;
	while (t--) {
		cin >> a >> b >> c;
		ans = 0;
		max_c = c;
		if (c % 2 == 1) {
			max_c = c - 1;
		}
		if (max_c >= 2*b) {
			ans += (3*b);
			b = 0;
		} else {
			ans += (max_c + max_c / 2);
			b -= (max_c / 2);
		}

		max_b = b;
		if (b % 2 == 1) {
			max_b = b - 1;
		}
		if (max_b >= 2*a) {
			ans += (3*a);
			a = 0;
		} else {
			ans += (max_b + max_b / 2);
			// b -= (max_b / 2);
		}

		cout << ans << endl;

	}
	return 0;
}