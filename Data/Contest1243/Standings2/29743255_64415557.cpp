#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int cnt[26];
int main(void) {
	int k;
	cin >> k;
	while (k--) {
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a']++;
			cnt[t[i] - 'a']++;
		}
		bool can = true;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 2 != 0) {
				can = false;
				break;
			}
		}
		if (can) {
			cout << "Yes" << endl;
			vector<pair<int, int>> res;
			for (int i = 0; i < n; i++) {
				if (s[i] != t[i]) {
					for (int j = i + 1; j < n; j++) {
						if (s[j] == s[i]) {
							res.emplace_back(j, i);
							swap(s[j], t[i]);
							break;
						} else if (t[j] == s[i]) {
							res.emplace_back(j, j);
							swap(s[j], t[j]);
							res.emplace_back(j, i);
							swap(t[i], s[j]);
							break;
						}
					}
				}
			}
			cout << res.size() << endl;
			for (auto p : res) {
				cout << p.first + 1 << " " << p.second + 1 << endl;
			}
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
