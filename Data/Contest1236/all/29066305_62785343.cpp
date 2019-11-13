#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t; while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		for(int x = 0; x <= a; x++) {
			int y = min(b - 2 * x, c / 2);
			ans = max(ans, 3 * (x + y));
		}
		cout << ans << endl;
	}
	return 0;
}
