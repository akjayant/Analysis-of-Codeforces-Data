#include <bits/stdc++.h>

using namespace std;

int t;
string s, ans = "";

int main() {
	cin >> t;
	for (int i = 0; i < 100;++i) ans += 'R';
	while (t--) {
		int a, b, c, a1 = 0, b1 = 0, c1 = 0, n;
		cin >> n;
		cin >> a >> b >> c;
		n = a + b + c;
		for (int i = 0; i < n; ++i) ans[i] = '.';
		cin >> s;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'R') ++b1;
			else if (s[i] == 'P') ++c1;
			else if (s[i] == 'S') ++a1;
		}
		int k = min(a1, a) + min(b1, b) + min(c1, c);
		if (k < ((n / 2) + (n % 2 != 0))) cout << "NO"; else {
			cout << "YES\n";
			for (int i = 0; i < n; ++i) {
				if (s[i] == 'R') {
					if (b) {
						--b;
						ans[i] = 'P';
					}
				} 
				if (s[i] == 'P') {
					if (c) {
						--c;
						ans[i] = 'S';
					}
				}
				if (s[i] == 'S') {
					if (a) {
						--a;
						ans[i] = 'R';
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				if (ans[i] == '.') {
					if (a) {
						--a;
						ans[i] = 'R';
					} else if (b) {
						--b;
						ans[i] = 'P';
					} else if (c) {
						--c;
						ans[i] = 'S';
					}
				}
			}
			for (int i = 0; i < n; ++i) cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}
