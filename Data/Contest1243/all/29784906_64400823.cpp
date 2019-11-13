#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 55;
const int mod = 1e9 + 7;
const long long INF = 1e18 + 12;
const int inf = 1e9;

int main () {
	boost;
	int t;
	cin >> t;
	while (t--) {
		int n; string a, b;
		cin >> n >> a >> b;
		vector <pair <int, int> > ans;
		for (int i = 0 ; i < n ; ++ i) {
			char f = a[i], s = b[i];
			if (f == s) continue;
			for (int j = i + 1 ; j < n ; ++ j) {
				char cur = a[j];
				if (cur == s) {
					ans.push_back ({j + 1, j + 1});
					swap (a[j], b[j]);
					ans.push_back ({i + 1, j + 1});
					swap (a[i], b[j]);
					break;
				}
				if (cur == f) {
					ans.push_back ({j + 1, i + 1});
					swap (b[i], a[j]);
					break;
				}
				cur = b[j];
				if (cur == f) {
					ans.push_back ({j + 1, j + 1});
					swap (a[j], b[j]);
					ans.push_back ({j + 1, i + 1});
					swap (a[j], b[i]);
					break;
				}
				if (cur == s) {
					ans.push_back ({i + 1, j + 1});
					swap (b[j], a[i]);
					break;
				}
			}
		}
		if (a != b) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		cout << ans.size() << "\n";
		for (auto p : ans) cout << p.first << " " << p.second << "\n";
	}
}