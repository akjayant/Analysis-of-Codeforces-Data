#include <bits/stdc++.h>
using namespace std;

int main (void) {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		vector <int> a(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		sort(a.begin(), a.end());

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] <= (n-i))
				ans = max(ans, a[i]);
			if ((n-i) <= a[i])
				ans = max(ans, (n-i));
		}

		cout << ans << "\n";
	}
}