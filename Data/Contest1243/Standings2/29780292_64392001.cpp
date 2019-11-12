#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	vector<pair<int, int>> ans;

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == t[i]) {
			continue;
		}

		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j]) {
				swap(t[i], s[j]);
				ans.emplace_back(j, i);
				break;
			}
		}

		if (s[i] == t[i]) {
			continue;
		}

		for (int j = i + 1; j < n; j++) {
			if (s[i] == t[j]) {
				swap(t[j], s[n - 1]);
				ans.emplace_back(n - 1, j);
				ans.emplace_back(n - 1, i);
				swap(t[i], s[n - 1]);
				break;
			}
		}

		if (s[i] != t[i]) {
			cout << "No\n";
			return;
		}
	}

	if (s[n - 1] != t[n - 1]) {
		cout << "No\n";
		return;
	}

	cout << "Yes\n";

	cout << ans.size() << endl;

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	}

}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
    	solve();
    }

    return 0;
}