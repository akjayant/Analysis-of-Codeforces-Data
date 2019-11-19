
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#define ll long long


using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t, p;
	ll P = 0, Q = 0, n, m;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		P = 0;
		Q = 0;
		cin >> n;
		for (ll j = 0; j < n; ++j) {
			cin >> p;
			if (p % 2 == 0) ++P;
		}
		cin >> m;
		for (ll j = 0; j < m; ++j) {
			cin >> p;
			if (p % 2 == 0) ++Q;
		}
		cout << 2 * P * Q + n * m - P * m - Q * n << "\n";
	}
	
}