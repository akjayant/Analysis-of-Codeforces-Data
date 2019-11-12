// In The Name Of GOD
#include<bits/stdc++.h>

using namespace std;

int q, n;
string s, t;

int32_t main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cerr << "HELLO WORLD:)\n";
	cin >> q;
	while (q--) {
		vector<pair<int, int>> ans;
		cin >> n >> s >> t;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				vector<int> vec;
				int p = i, x = -1;
				vec.push_back(i);
				while (!vec.empty()) {
					for (int j = i + 1; j < n; j++) {
						if (t[j] == t[vec.back()]) {
							x = j;
							break;
						}
					}
					if (x == -1) {
						for (int j = i + 1; j < n; j++) {
							if (s[j] == t[vec.back()]) {
								x = j;
								break;
							}
						}
						if (x == -1) {
							cout << "No\n";
							goto nex;
						}
						vec.push_back(x);
					}
					else {
						for (int i = (int)vec.size() - 1; ~i; i--) {
							swap(t[x], s[vec[i]]);
							ans.push_back({ vec[i] + 1, x + 1 });
						}
						vec.clear();
					}
				}
			}
		}
		cout << "Yes\n";
		cout << ans.size() << '\n';
		for (auto u : ans)
			cout << u.first << ' ' << u.second << '\n';
	nex:;
	}
}