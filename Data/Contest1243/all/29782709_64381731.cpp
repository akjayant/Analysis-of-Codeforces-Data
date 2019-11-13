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
		string a, b;
		cin >> a >> b;

		bool flag = true;
		vector < pair < int, int > > moves;
		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i]) continue;

			bool found = false;
			for (int j = i + 1; j < n; ++j) {
				if (b[j] == b[i]) {
					swap(a[i], b[j]);
					moves.push_back({i, j});
					found = true;
					break;
				}
			}
			if (found == false) {
				for (int j = i + 1; j < n; ++j) {
					if (a[j] == a[i]) {
						swap(b[i], a[j]);
						moves.push_back({j, i});
						found = true;
						break;
					}
				}
			}
			if (found == false) {
				for (int j = i + 1; j < n; ++j) {
					if (a[i] == b[j]) {
						moves.push_back({i + 1, j});
						swap(a[i + 1], b[j]);

						moves.push_back({i + 1, i});
						swap(a[i + 1], b[i]);

						found = true;
						break;
					} else if (b[i] == a[j]) {
						moves.push_back({j, i + 1});
						swap(a[j], b[i + 1]);

						moves.push_back({i, i + 1});
						swap(a[i], b[i + 1]);

						found = true;
						break;
					}
				}
			}
			flag = min(flag, found);
		}

		if (flag && (int)moves.size() <= 2 * n) {
			cout << "Yes\n";
			cout << moves.size() << "\n";
			for (auto x : moves) {
				cout << x.first + 1 << " " << x.second + 1 << "\n";
			}
		} else {
			cout << "No\n";
		}
	}
	return 0;
}