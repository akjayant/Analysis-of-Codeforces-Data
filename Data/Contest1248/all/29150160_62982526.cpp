// *** creator : cfmasterr *** //
#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
  	int n;
  	cin >> n;
  	int o1 = 0, e1 = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x % 2 == 0) e1++;
			else o1++;
		}
		int m;
		cin >> m;
		int o2 = 0, e2 = 0;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if (x % 2 == 0) e2++;
			else o2++;
		}
		cout << o1 * o2 + e1 * e2 << '\n';
	}
  return 0;
}

