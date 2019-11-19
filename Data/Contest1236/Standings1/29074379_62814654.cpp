#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const int mod = 1e9 + 7;
int n, m, k, x[N], y[N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
set<int> R[N], C[N];
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		scanf("%d %d", x + i, y + i);
		R[x[i]].insert(y[i]);
		C[y[i]].insert(x[i]);
	}
	int sx = 1, sy = 1, d = 0;
	ll t = (ll)n * m - k - 1;
	int r1 = 1, r2 = n, c1 = 1, c2 = m;
	bool f = 0;
	while (t > 0) {
		ll pre = t;
		int bound;
		set<int>::iterator it;
		if (d == 0) {
			bound = c2;
			it = R[sx].lower_bound(sy);
			if (it != R[sx].end()) 
				bound = min(bound, (*it) - 1);
			t -= bound - sy;
			sy = bound;
			r1 = sx + 1;
		} else 
		if (d == 1) {
			bound = r2;
			it = C[sy].lower_bound(sx);
			if (it != C[sy].end()) 
				bound = min(bound, (*it) - 1);
			t -= bound - sx;
			sx = bound;
			c2 = sy - 1;
		} else 
		if (d == 2) {
			bound = c1;
			it = R[sx].lower_bound(sy);
			if (R[sx].size() && it != R[sx].begin()) {
				--it;
				bound = max(bound, (*it) + 1);
			}
			t -= sy - bound;
			sy = bound;
			r2 = sx - 1;
		} else {
			bound = r1;
			it = C[sy].lower_bound(sx);
			if (C[sy].size() && it != C[sy].begin()) {
				--it;
				bound = max(bound, (*it) + 1);
			}
			t -= sx - bound;
			sx = bound;
			c1 = sy + 1;
		}
		if (t == pre && f) break;
		d++;
		d %= 4;
		f = 1;
	}
	if (t) puts("No");
	else puts("Yes"); 
}