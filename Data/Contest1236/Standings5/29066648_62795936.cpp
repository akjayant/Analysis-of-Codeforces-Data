#include <cstdio>

const int MAXN = 310;

int n, f[MAXN][MAXN];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		if (i & 1)
			for (int j = 1; j <= n; j++)
				f[j][i] = (i - 1) * n + j;
		else
			for (int j = 1; j <= n; j++)
				f[j][i] = (i - 1) * n + (n - j + 1);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", f[i][j]);
		puts("");
	}

	// for (int i = 1; i <= n; i++)
	// 	for (int j = 1; j <= n; j++) {
	// 		if (i == j) continue;
	// 		int cnt = 0;

	// 		for (int a = 1; a <= n; a++)
	// 			for (int b = 1; b <= n; b++)
	// 				cnt += f[i][a] > f[j][b];

	// 		printf("%d %d => %d\n", i, j, cnt);
	// 	}

	return 0;
}
