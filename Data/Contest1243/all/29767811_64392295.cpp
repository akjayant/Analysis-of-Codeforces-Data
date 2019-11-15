#include<bits/stdc++.h>
using namespace std;

const int K = 26;

void solve() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	map<char, int> cnt;
	for (auto c : s) {
		cnt[c]++;
	}
	for (auto c : t) {
		cnt[c]++;
	}
	for (auto p : cnt) {
		if (p.second & 1) {
			cout << "No\n";
			return;
		}
	}
	vector<pair<int, int>> ops;
	for (int i = 0; i < n; i++) {
		if (s[i] != t[i]) {
			bool found = false;
			for (int j = i + 1; j < n; j++) {
				if (s[j] == s[i]) {
					ops.emplace_back(j + 1, i + 1);
					found = true;
					swap(s[j], t[i]);
					break;
				}
			}
			if (!found) {
				for (int j = i + 1; j < n; j++) {
					if (t[j] == s[i]) {
						ops.emplace_back(j + 1, j + 1);
						swap(s[j], t[j]);
						ops.emplace_back(j + 1, i + 1);
						swap(s[j], t[i]);
						break;
					}
				}
			}
		} 
	}
	cout << "Yes\n" << ops.size() << '\n';
	for (auto op : ops) {
		cout << op.first << " " << op.second << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}