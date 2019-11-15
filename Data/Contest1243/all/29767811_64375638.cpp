#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	while (k--) {
		int n;
		string s, t;
		cin >> n >> s >> t;
		vector<int> inds;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				inds.push_back(i);
			}
		}
		if ((int) inds.size() == 2) {
			swap(s[inds[0]], t[inds[1]]);
			if (s == t) {
				cout << "Yes\n";
				continue;
			}
			swap(s[inds[0]], t[inds[1]]);
			swap(t[inds[0]], s[inds[1]]);
			if (s == t) {
				cout << "Yes\n";
				continue;
			}
			cout << "No\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}