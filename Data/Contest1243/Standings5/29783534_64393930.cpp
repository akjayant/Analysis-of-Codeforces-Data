#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#include <queue>
#include <set>
#include <iterator>
#include <queue>
#include <string>
#include <functional>
#include <array>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> ch[1000] = {};

signed main() {
	int k, n;
	cin >> k;
	vector<string> ans;
	string s1, s2;
	string res;
	for (int i = 0; i < k; i++) {
		cin >> n;
		cin >> s1 >> s2;
		map<char, int> m;
		for (int j = 0; j < n; j++) {
			m[s1[j]] = m[s1[j]] + 1;
			m[s2[j]] = m[s2[j]] + 1;
		}
		bool f = 1;
		for (auto & kv : m) {
			if (kv.second % 2 == 1) {
				f = 0;
				break;
			}
		}
		if (f == 0) {
			res = "No";
		} else {
			res = "Yes";
			for (int j = 0; j < n; j++) {
				// cout << s1 << " " << s2 << "\n"
				if (s1[j] != s2[j]) {
					int ind = -1;
					for (int k = j + 1; k < n; k++) {
						if (s1[k] == s1[j]) {
							ind = k;
							break;
						}
					}
					if (ind != -1) {
						ch[i].push_back({ind, j});
						swap(s1[ind], s2[j]);
					} else {
						int ind2 = -1;
						for (int k = j + 1; k < n; k++) {
							if (s2[k] == s1[j]) {
								ind2 = k;
								break;
							}
						}
						ch[i].push_back({j + 1, ind2});
						ch[i].push_back({j + 1, j});
						swap(s1[j + 1], s2[ind2]);
						swap(s1[j + 1], s2[j]);
					}
				}
			}
			
		}
		ans.push_back(res);
	}
	for (int i = 0; i < k; i++) {
		cout << ans[i] << "\n";
		if (ch[i].size() != 0) {
			cout << ch[i].size() << "\n";
			for (auto e : ch[i]) {
				cout << e.first + 1 << " " << e.second + 1 << "\n";
			}
		}
	}
    return 0;
}

