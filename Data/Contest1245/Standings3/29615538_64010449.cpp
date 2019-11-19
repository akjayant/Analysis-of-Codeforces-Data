#include  <bits/stdc++.h>
using namespace std;

namespace bruteforce {
	int solve(int l, int r) {
		long long ret = 0;
		for(int i = l; i <= r; i++) {
			for(int j = l; j <= r; j++) {
				if((i & j) == 0) ret++;
				/*if(i + j == (i ^ j)) {
					ret++;
				}*/
			}
		} return ret;
	}
}
using ll = long long;

ll dp[2][2][2][2][35];
int l, r;
ll f(int x, int y, int p, int q, int k) {
	if(k == -1) return 1;
	ll &ret = dp[x][y][p][q][k];
	if(ret != -1) return ret;
	ret = 0;
	int l1 = x ? ((l >> k) & 1) : 0;
	int r1 = y ? ((r >> k) & 1) : 1;
	int l2 = p ? ((l >> k) & 1) : 0;
	int r2 = q ? ((r >> k) & 1) : 1;
	for(int i = l1; i <= r1; i++) {
		for(int j = l2; j <= r2; j++) {
			if(i == 1 and j == 1) continue;
			ret += f(x && (((l >> k) & 1) == i),
							y && (((r >> k) & 1) == i),
							p && (((l >> k) & 1) == j),
							q && (((r >> k) & 1) == j),
							k - 1);
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	// freopen("in", "r", stdin);
	int t; cin >> t;
	while(t--) {
		memset(dp, -1, sizeof dp);
		cin >> l >> r;
		cout << f(1, 1, 1, 1, 29) << endl;
	}
	return 0;
}