#include <cstdio>
#include <cstring>

#define R register
int T, l, r;
int stk1[40], stk2[40], top;
long long f[40][2][2];

long long dfs(R int pos, R bool lim1, R bool lim2) {
	if(!~pos) return 1;
	if(~f[pos][lim1][lim2]) return f[pos][lim1][lim2];
	R long long ret = 0;
	R int up1 = lim1? stk1[pos]: 1;
	R int up2 = lim2? stk2[pos]: 1;
	for(R int i = 0; i <= up1; ++i) {
		for(R int j = 0; j <= up2; ++j) {
			if(i && j) continue;
			ret += dfs(pos - 1, lim1 && i == up1, lim2 && j == up2);
		}
	}
	f[pos][lim1][lim2] = ret;
	return ret;
}

long long solve(R int x, R int y) {
	if(!~x || !~y) return 0;
	for(top = 0; x || y; x >>= 1, y >>= 1) stk1[top] = x & 1, stk2[top++] = y & 1;
	memset(f, -1, sizeof(f));
	return dfs(top - 1, 1, 1);
}

int main() {
	for(scanf("%d", &T); T--; ) {
		scanf("%d%d", &l, &r);
		printf("%lld\n", solve(r, r) - solve(r, l - 1) - solve(l - 1, r) + solve(l - 1, l - 1));
	}
	return 0;
}
