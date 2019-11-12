#include <bits/stdc++.h>

using namespace std;

inline void Boost() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}
typedef long long int ll;
typedef long double ld;

int main() {
	Boost();

	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		vector < int > v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		int ans = 1;
		sort(v.begin(), v.end());
		for (int l = 1; l <= n; ++l) {
			for (int j = 0; j < n; ++j) {
				if (v[j] >= l) {
					int total = n - j;
					if (total >= l) {
						ans = l;
					}
				}
			}
		}

		cout << ans << "\n";
	}
	return 0;
}