#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; cin >> T;
	while(T--) {
		int a, b, c; cin >> a >> b >> c;
		int ans = 0;
		int d = min(c / 2, b);
		ans += 3 * d;
		b -= d;
		d = min(b / 2, a);
		ans += 3 * d;
		cout << ans << endl;
	}
	return 0;
}