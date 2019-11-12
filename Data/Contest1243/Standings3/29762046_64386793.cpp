#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int k;
	cin >> k;

	for (int l = 0; l < k; l++) {
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		
		set<char> cs;
		multiset<char> cms;
		for (int i = 0; i < n; i++) {
			cs.insert(s[i]);
			cs.insert(t[i]);
			cms.insert(s[i]);
			cms.insert(t[i]);
		}
		bool fails = false;
		for (char x : cs) {
			if (cms.count(x) % 2 != 0) {
				fails = true;
				break;
			}
		}
		if (fails) {
			cout << "No" << endl;
			continue;
		}

		vector<pair<int, int>> swaps;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) continue;

			bool done = false;
			for (int j = i + 1; j < n; j++) {
				if (s[j] == s[i]) {
					swaps.push_back({ j, i });
					swap(s[j], t[i]);
					done = true;
					break;
				}
			}
			if (done) continue;

			for (int j = i + 1; j < n; j++) {
				if (t[j] == s[i]) {
					swaps.push_back({ i + 1, j });
					swap(s[i + 1], t[j]);
					swaps.push_back({ i + 1, i });
					swap(s[i + 1], t[i]);
					break;
				}
			}
		}

		cout << "Yes" << endl;
		cout << swaps.size() << endl;
		for (auto p : swaps) {
			cout << p.first + 1 << " " << p.second + 1 << endl;
		}
	}

	return 0;
}
