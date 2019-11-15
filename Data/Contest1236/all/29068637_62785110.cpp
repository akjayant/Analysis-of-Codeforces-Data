#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (i <= a && i * 2 + j <= b && j * 2 <= c) {
				ans = max(ans, i + i * 2 + j + j * 2);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int notests = 1;
	cin >> notests;
	while (notests--) {
		solve();
	}
	return 0;
}