#include <bits/stdc++.h>
using namespace std;

int tc, n, a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a + n, greater<int>());
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > i) {
				ans = i + 1;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}