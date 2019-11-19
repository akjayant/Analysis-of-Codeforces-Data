#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 32;

int l[N], r[N];
ll dp[2][2][2][2][N];

ll DP(int f1, int f2, int f3, int f4, int p) {
	if(p >= N) return 1;
	ll &ret = dp[f1][f2][f3][f4][p];
	if(ret != -1) return ret;
	ret = 0;

	int l1 = (f1 ? 0 : l[p]);
	int r1 = (f2 ? 1 : r[p]);
	int l2 = (f3 ? 0 : l[p]);
	int r2 = (f4 ? 1 : r[p]);

	for(int x = l1; x <= r1; x++) {
		for(int y = l2; y <= r2; y++) {
			if(x == 1 && y == 1) continue;

			int _f1 = (f1 | (x > l[p]));
			int _f2 = (f2 | (x < r[p]));
			int _f3 = (f3 | (y > l[p]));
			int _f4 = (f4 | (y < r[p]));
			ret += DP(_f1, _f2, _f3, _f4, p + 1);
		}
	}
 	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int x, y; scanf("%d %d", &x, &y);
		for(int i = N - 1; i >= 0; i--) {
			l[i] = x % 2;
			x /= 2;
		}
		for(int i = N - 1; i >= 0; i--) {
			r[i] = y % 2;
			y /= 2;
		}
		memset(dp, -1, sizeof dp);
		printf("%I64d\n", DP(0, 0, 0, 0, 0));
	}
	return 0;
}