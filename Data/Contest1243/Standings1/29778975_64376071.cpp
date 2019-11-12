#include <bits/stdc++.h>

using namespace std;

const int M = 1e3 + 3;
int q;

int main () {
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int t[n+2] = {0};
		for (int i = 0; i < n; i++) cin >> t[i];
		sort (t, t+n, greater <int> ());
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max (ans, min (i+1, t[i]));
			//cout << i << ' ' << min (i+1, t[i]) << endl;
		}
		cout << ans << endl;
	}
}