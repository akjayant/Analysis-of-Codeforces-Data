#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int t, n, a, b, c, x;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> a >> b >> c;
		cin >> s;
		string ans(n, 'x');
		x = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'R' && b) {
				--b;
				++x;
				ans[i] = 'P';
				continue;
			} else if (s[i] == 'P' && c) {
				--c;
				++x;
				ans[i] = 'S';
			} else if (s[i] == 'S' && a) {
				--a;
				++x;
				ans[i] = 'R';
			}
		}

		if (x < (n + 1) / 2) {
			cout << "No" << endl;
			continue;
		}

		for (int i = 0; i < n; ++i) {
			if (ans[i] != 'x') continue;
			if (a) {
				--a;
				ans[i] = 'R';
			} else if (b) {
				--b;
				ans[i] = 'P';
			} else if (c) {
				--c;
				ans[i] = 'S';
			} else assert(false);
		}
		cout << "Yes\n" << ans << endl;

	}
	return 0;
}