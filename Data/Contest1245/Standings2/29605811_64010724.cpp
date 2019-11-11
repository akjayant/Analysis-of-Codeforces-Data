#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second

#define pb push_back

void solve(int n, int rock, int paper, int sc, string s) {
	vector<char> ans(n, 0);

	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == 'S' && rock > 0) {
			ans[i] = 'R';
			++cnt;
			--rock;
		}

		if (s[i] == 'P' && sc > 0) {
			ans[i] = 'S';
			++cnt;
			--sc;
		}

		if (s[i] == 'R' && paper > 0) {
			ans[i] = 'P';
			++cnt;
			--paper;
		}
	}

	if (cnt * 2 < n) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		if (ans[i] == 0) {
			if (rock > 0) {
				ans[i] = 'R';
				--rock;
				continue;
			}

			if (paper > 0) {
				ans[i] = 'P';
				--paper;
				continue;
			}

			if (sc > 0) {
				ans[i] = 'S';
				--sc;
				continue;
			}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i];
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t --> 0) {
		int n, a, b, c;
		string s;
		cin >> n >> a >> b >> c >> s;
		solve(n, a, b, c, s);
	}
	return 0;
}
