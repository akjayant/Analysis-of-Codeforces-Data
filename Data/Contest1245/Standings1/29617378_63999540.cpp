#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, a, b, c;
		string s;
		cin >> n >> a >> b >> c >> s;
		string ans(n, '#');
		int m = 0;
		for (int i = 0; i != n; ++i) {
			if (s[i] == 'R') {
				if (b) {
					ans[i] = 'P';
					++m, --b;
				}
			}
			if (s[i] == 'P') {
				if (c) {
					ans[i] = 'S';
					++m, --c;
				}
			}
			if (s[i] == 'S') {
				if (a) {
					ans[i] = 'R';
					++m, --a;
				}
			}
		}
		if (m + m < n) {
			cout << "NO" << endl;
			continue;
		}
		for (int i = 0; i != n; ++i) if (ans[i] == '#') {
			if (a) {
				ans[i] = 'R';
				--a;
			} else if (b) {
				ans[i] = 'P';
				--b;
			} else {
				ans[i] = 'S';
			}
		}
		cout << "YES" << endl << ans << endl;
	}
}
