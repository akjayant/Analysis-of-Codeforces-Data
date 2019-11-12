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

		int pa, pb;
		pa = pb = -1;
		for (int i = 0; i < n; ++i) {
			if (a[i] != b[i]) {
				if (pa == -1) {
					pa = i;
				} else {
					pb = i;
				}
			}
		}

		if (pa == -1 || pb == -1) {
			cout << "No\n";
			continue;
		}
		swap(a[pa], b[pb]);
		if (a != b) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
	return 0;
}