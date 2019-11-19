#pragma GCC optimize(2)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define MP make_pair
using namespace std;

typedef double D;
const int N = 13, n = 10;
int a[N][N];
pair <int, int> nx[N][N];
D f[N][N];

D dfs (const int x, const int y) {
	if (x == 1 && y == 1) return 0;
	if (f[x][y] >= 0) return f[x][y];
	f[x][y] = 0;
	register int sx = x, sy = y;
	int k = 0;
	for (register int What = 1; What <= 6; ++What) {
		if (sx == 1 && sy == 1) {
			k = 7 - What;
			break;
		}
		int p = nx[sx][sy].first, q = nx[sx][sy].second;
		sx = p, sy = q;
		if (a[sx][sy]) f[x][y] += min (dfs (sx - a[sx][sy], sy), dfs (sx, sy));
		else f[x][y] += dfs (sx, sy);
	}
	return f[x][y] = (f[x][y] + 6) / (6.0 - k);
}

int main () {
	int i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			f[i][j] = -100;
			scanf ("%d", &a[i][j]);
			if (i & 1) {
				if (j == 1)
					nx[i][j] = MP (i - 1, j);
				else
					nx[i][j] = MP (i, j - 1);
			}
			else {
				if (j == 10)
					nx[i][j] = MP (i - 1, j);
				else
					nx[i][j] = MP (i, j + 1);
			}
		}
	}
	printf ("%.10lf\n", dfs (10, 1));
	return 0;
}

