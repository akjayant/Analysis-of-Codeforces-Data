#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr), ios_base::sync_with_stdio(false);
	map<char, int> match;
	match['R'] = 1, match['P'] = 2, match['S'] = 0;
	char toCh[] = "RPS";
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[3]; cin >> a[0] >> a[1] >> a[2];
		string bob; cin >> bob;
		string alice;
		int ans = 0;
		for (char c : bob) {
			if (a[match[c]]) {
				++ans;
				--a[match[c]];
				alice.push_back(toCh[match[c]]);
			} else {
				alice.push_back('x');
			}
		}
		vector<char> tmp;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < a[i]; j++) tmp.push_back(toCh[i]);
		}
		for (char &c : alice) {
			if (c == 'x') {
				c = tmp.back();
				tmp.pop_back();
			}
		}
		if (ans < (n + 1) / 2) {
			cout << "NO\n";
		} else {
			cout << "YES\n" << alice << '\n';
		}
	}
}
