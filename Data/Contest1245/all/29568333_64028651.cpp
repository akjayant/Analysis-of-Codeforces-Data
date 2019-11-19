#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
using namespace std;
int cnt, digx[40], digy[40];
bool vis[40][2][2][2][2][2][2];
LL dp[40][2][2][2][2][2][2];

LL dfs(int p, int pre0a, int lima, int lim2a, int pre0b, int limb, int lim2b) {
	if (!p) return !pre0a && !pre0b;
	if (vis[p][pre0a][lima][lim2a][pre0b][limb][lim2b])
		return dp[p][pre0a][lima][lim2a][pre0b][limb][lim2b];
	vis[p][pre0a][lima][lim2a][pre0b][limb][lim2b] = 1;
	LL &v = dp[p][pre0a][lima][lim2a][pre0b][limb][lim2b];
	v = 0;
	int upa = lima ? digy[p] : 1;
	int upb = limb ? digy[p] : 1;
	int downa = lim2a ? digx[p] : 0;
	int downb = lim2b ? digx[p] : 0; 
	for (int a = downa; a <= upa; ++a)
		for (int b = downb; b <= upb; ++b)
			if ((a & b) == 0)
				v += dfs(p - 1, pre0a && a == 0, lima && a == upa, lim2a && a == downa, pre0b && b == 0, limb && b == upb, lim2b && b == downb);
	return v;
}

//1 ~ x
LL solve(int x, int y) {
	cnt = 0;
	memset(vis, 0, sizeof(vis));
	memset(digx, 0, sizeof(digx));
	memset(digy, 0, sizeof(digy));
	while (x) {
		digx[++cnt] = x & 1;
		x >>= 1;
	}
	cnt = 0;
	while (y) {
		digy[++cnt] = y & 1;
		y >>= 1;
	}
	return dfs(cnt, 1, 1, 1, 1, 1, 1);
}

int main()
{
	#ifdef DEBUG
	freopen("text.in", "r", stdin);
	#endif
	int t, l, r;
	scanf("%d", &t);
	while (t--) {
		LL ans = 0ll;
		scanf("%d%d", &l, &r);
		if (!r) {
			printf("1\n");
			continue;
		}
		if (!l) ans += 2ll * r + 1, ++l;
		ans += solve(l, r);
		printf("%I64d\n", ans);
	}
	return 0;
}