/*
 * Author: apikdech
 * Time: 16:07:33 20-10-2019
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, m, o1 = 0, o2 = 0, e1 = 0, e2 = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x & 1) o1++;
			else e1++;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if (x & 1) o2++;
			else e2++;
		}
		cout << o1*o2 + e1*e2 << "\n";
	}
	return 0;
}
