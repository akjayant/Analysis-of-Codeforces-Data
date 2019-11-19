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
 
int t, n, m;

int main () {
	cin >> t;

	while (t--) {
		cin >> n;

		ll q_odd = 0, p_odd = 0, q_even = 0, p_even = 0;

		for (int i = 0; i < n; i++) {
			int p;
			scanf ("%d", &p);
			if (p & 1) p_odd++;
			else p_even++;
		}

		cin >> m;

		for (int i = 0; i < m; i++) {
			int q;
			scanf ("%d", &q);
			if (q & 1) q_odd++;
			else q_even++;
		}

		cout << q_odd * p_odd + q_even * p_even << endl;
	}
}