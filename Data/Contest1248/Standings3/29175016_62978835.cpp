#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
  	cin.tie(0);
	int t;
	cin >> t;
	for(int tc = 0; tc < t; tc++) {
		int n, m, p, q;
		int o1 = 0, o2 = 0;
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> p;
			if(p % 2) o1 ++;
		}
		cin >> m;
		for(int i = 0; i < m; i++) {
			cin >> q;
			if(q % 2) o2 ++;
		}
		int e1 = n - o1;
		int e2 = m - o2;
		long long ans = o1 * 1LL * o2 + e1 * 1LL * e2;
		cout << ans << endl; 
	}
	return 0;
}
