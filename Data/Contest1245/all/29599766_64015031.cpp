#include <bits/stdc++.h>

using namespace std;

int vis[41][2][2];
long long f[41][2][2];
int idx = 5;
int X, Y;
long long dfs(int x, int flag1, int flag2) {
	if (x == -1) return 1;
	if (vis[x][flag1][flag2] == idx) return f[x][flag1][flag2];
	vis[x][flag1][flag2] = idx;
	long long ans = 0;
	int a = (X >> x) & 1, b = (Y >> x) & 1;
	int edx = flag1 ? a : 1;
	int edy = flag2 ? b : 1;
	for (int i = 0; i <= edx; i ++)
		for (int j = 0; j <= edy; j ++) {
			if ((i & j) == 0) ans += dfs(x - 1, flag1 & (i == edx), flag2 & (j == edy));
		}
	return f[x][flag1][flag2] = ans;
}

long long calc(int xx, int yy) {
	if (xx < 0 || yy < 0) return 0;
	X = xx, Y = yy;
	++ idx;
	return dfs(30, 1, 1);
}
int main( ) {
	int t;
	int l, r;
	scanf("%d", &t);
	while (t --) {
		scanf("%d %d", &l, &r);
		printf("%I64d\n", calc(r, r) - 2 * calc(l - 1, r) + calc(l - 1, l - 1));
	}
	return 0;
}

