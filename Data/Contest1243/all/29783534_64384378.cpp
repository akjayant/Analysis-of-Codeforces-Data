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

signed main() {
	int k, n;
	cin >> k;
	vector<string> ans;
	string s1, s2;
	for (int i = 0; i < k; i++) {
		cin >> n;
		cin >> s1 >> s2;
		set<char> ss1, ss2;
		int s = 0;
		int ns = 0;
		for (int j = 0; j < n; j++) {
			if (s1[j] == s2[j]) {
				s++;
			} else {
				ns++;
				ss1.insert(s1[j]);
				ss2.insert(s2[j]);
			}
		}
		string res = "";
		if (ns == 0) {
			res = "Yes";
		} else if (ns == 2) {
			bool f = 1;
			if (ss1.size() == 1 && ss2.size() == 1) {
				f = 1;
			} else {
				f = 0;
			}
			if (f) {
				res = "Yes";
			} else {
				res = "No";
			}
		} else {
			res = "No";
		}
		ans.push_back(res);
	}
	for (auto e : ans) {
		cout << e << "\n";
	}
    return 0;
}

