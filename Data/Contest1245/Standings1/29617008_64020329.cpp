#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int A[20][20], vis[20][20];
pair<int, int> go[20][20];
double d[20][20];
double dp(int r, int c) {
	if (vis[r][c]) return d[r][c];
	vis[r][c] = true; d[r][c] = 0;
	double& ans = d[r][c];
	pair<int, int> pos(r, c);
	for (int k = 1; k <= 6; ++k) {
		pos = go[pos.first][pos.second];
		double p = dp(pos.first, pos.second);
		if (A[pos.first][pos.second] > 0) {
			p = min(p, dp(pos.first - A[pos.first][pos.second], pos.second));
		}
		ans += (p + 1) / 6.0;
	}
	return ans;
}
int main() {
	//freopen("in.txt", "r", stdin);
	for (int i = 1; i <= 10; ++i)
		for (int j = 1; j <= 10; ++j)
			scanf("%d", &A[i][j]);
	for (int i = 10; i >= 1; --i) {
		if (i % 2 == 0) {
			for (int j = 1; j <= 10; ++j)
				go[i][j] = make_pair(i, j + 1);
			go[i][10] = make_pair(i - 1, 10);
		}
		else {
			for (int j = 10; j >= 1; --j)
				go[i][j] = make_pair(i, j - 1);
			go[i][1] = make_pair(i - 1, 1);
		}
	}
	for (int i = 1; i <= 6; ++i) 
		vis[1][i] = true;
	d[1][1] = 0;
	d[1][2] = 6;
	d[1][3] = 3 + 0.5 * d[1][1] + 0.5 * d[1][2];
	d[1][4] = 2 + 1.0 / 3 * (d[1][1] + d[1][2] + d[1][3]);
	d[1][5] = 1.5 + 1.0 / 4 * (d[1][1] + d[1][2] + d[1][3] + d[1][4]);
	d[1][6] = 1.2 + 1.0 / 5 * (d[1][1] + d[1][2] + d[1][3] + d[1][4] + d[1][5]);
	double ans = dp(10, 1);
	printf("%.10f\n", ans);
	return 0;
}