#include <bits/stdc++.h>

using namespace std;

int cnt1, cnt2, cnt3, cnt4;

int main() {
	int t; cin >> t;
	while(t--) {
		int n, m, p, q;
		cnt1 = cnt2 = cnt3 = cnt4 = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> p;
			if(p % 2) cnt1++;
			else cnt2++;
		}
		cin >> m;
		for(int i = 1; i <= m; i++) {
			cin >> q;
			if(q % 2) cnt3++;
			else cnt4++;
		}
		cout << 1LL * cnt1 * cnt3 + 1LL * cnt2 * cnt4 << endl;
	}
	return 0;
}