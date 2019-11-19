#include <bits/stdc++.h>

using namespace std;

bool vis[11][11];
int h[11][11];
double f[11][11];
pair<int, int> nxt[11][11][7];
double dp(int x, int y) {
	if (x == 1 && y == 1) return 0;
	if (vis[x][y]) return f[x][y];
	vis[x][y] = true;
	double count = 1.;
	double ans = 1.;
	for (int i = 1; i <= 6; i ++) {
		pair<int, int> tmp = nxt[x][y][i];
		if (tmp.first == 0) count -= 1. / 6;
		else if (h[tmp.first][tmp.second]) {
			double g = min(dp(tmp.first - h[tmp.first][tmp.second], tmp.second), dp(tmp.first, tmp.second));
			ans += g / 6.;
		}
		else ans += dp(tmp.first, tmp.second) / 6.;
	}
	return f[x][y] = ans / count;
}
int main( ) {
	int n;
	bool cur = true;
	for (int i = 1; i <= 10; i ++)
		for (int j = 1; j <= 10; j ++)
			scanf("%d", &h[i][j]);
	
	for (int i = 10; i >= 1; i --) {
		for (int j = 1; j <= 10; j ++) {
			if (cur) {
				for (int k = 1; k <= 6; k ++)
					if (j + k <= 10) nxt[i][j][k] = make_pair(i, j + k);
					else nxt[i][j][k] = make_pair(i - 1, 10 - (j + k - 10) + 1);
			}
			else {
				for (int k = 1; k <= 6; k ++)
					if (j - k >= 1) nxt[i][j][k] = make_pair(i, j - k);
					else nxt[i][j][k] = make_pair(i - 1, 0 + (1 - (j - k)));
			}
		}
		cur ^= 1;
	}
	printf("%.9f\n", dp(10, 1));
	return 0;
}
