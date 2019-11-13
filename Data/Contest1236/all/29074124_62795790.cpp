#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#define M 1000000007
using namespace std;
typedef long long ll;

ll grid[1010][1010];

ll powr(ll a, ll p, ll m) {
	if (p == 0) {
		return 1;
	}
	if (p%2 == 0) {
		ll x = powr(a, p/2, m);
		return 	(x*x)%m;
	}
	return (a*powr(a, p-1, m) ) % m;
}

int main () {
	// freopen ("input.txt", "r", stdin);
	ll t, n, i, j, v;
	// cin >> t;
	t = 1;
	while (t--) {
		cin >> n;
		v = 1;
		for (i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				for (j = 1; j <= n; j++) {
					grid[i][j] = v;
					v++;
				}
			} else {
				for (j = n; j > 0; j--) {
					grid[i][j] = v;
					v++;
				}
			} 
		}

		for (j = 1; j <= n; j++) {
			for (i = 1; i <= n; i++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		
	}
	return 0;
}