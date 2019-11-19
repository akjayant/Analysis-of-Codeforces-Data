#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <set>
#include <cstring>
#include <assert.h>
#include <cstdlib>
#include <cmath>
#include <queue>
 
using namespace std;
 
typedef long long ll;
 
const ll INF = 1e9, MOD = 1e9 + 7, MOD2 = 1e6 + 3;

int t;

int main () {
	cin >> t;

	while (t--) {
		int a, b, c, d, k;
		bool ok = false;
		cin >> a >> b >> c >> d >> k;

		for (int i = 0; i <= k; i++) {
			if (a <= c * i && b <= d * (k - i)) {
				cout << i << ' ' << k - i << endl;
				ok = true;
				break;
			}
		}

		if (!ok) cout << -1 << endl;
	}
}