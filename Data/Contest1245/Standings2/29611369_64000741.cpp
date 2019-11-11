#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, R, P, S;
	cin >> n >> R >> P >> S;
	string s;
	cin >> s;
	int cnt = 0;
	vector<char> ans;
	ans.assign(n, 'x');
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'R') {
			if (P > 0) {
				cnt += 1;
				P -= 1;
				ans[i] = 'P';
			}
			continue;
		}
		if (s[i] == 'P') {
			if (S > 0) {
				cnt += 1;
				S -= 1;
				ans[i] = 'S';
			}
			continue;
		}

		if (s[i] == 'S') {
			if (R > 0) {
				cnt += 1;
				R -= 1;
				ans[i] = 'R';
			}
			continue;
		}
	}
	if (cnt < (n / 2) + (n % 2)) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		if (ans[i] == 'x') {
			if (R > 0) {
				R -= 1;
				ans[i] = 'R';
				continue;
			}
			if (P > 0) {
				P -= 1;
				ans[i] = 'P';
				continue;
			}
			if (S > 0) {
				S -= 1;
				ans[i] = 'S';
				continue;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i];
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}