#include <bits/stdc++.h>
using namespace std;
const int N = 305;

int n, a[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1, j = 0, mv = 1, x = 0; i <= n*n; i++) {
		if (i%n == 1) mv *= -1, ++x;
		else j += mv;
		if (j == n+1) j = 1;
		if (j == 0) j = n;
		a[x][j] = i;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			printf("%d%c", a[j][i], " \n"[j == n]);
	return 0;
}
