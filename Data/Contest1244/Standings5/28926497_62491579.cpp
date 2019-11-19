#include <bits/stdc++.h>

using namespace std;

typedef double de;
typedef long long int LL;
const int N = 100100;
const LL INF = (1ll << 60);

LL a[N][3];
LL d[N][3][3];
int vis[N];
int deg[N];
vector< int > b[N];
int pre[N], to[N];

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int n, po1, po2;
	scanf("%d", &n);

	for (int j = 0;j < 3; ++j)
		for (int i = 1;i <= n; ++i)
			scanf("%lld", &a[i][j]);

	for (int i = 1;i < n; ++i) {
		scanf("%d%d", &po1, &po2);
		deg[po1] ++, deg[po2] ++;
		b[po1].push_back( po2 );
		b[po2].push_back( po1 );
	}

	for (int i = 1;i <= n; ++i)
		if (deg[i] > 2) {
			printf("-1");
			return 0;
		}

	int rt;
	for (int i = 1;i <= n; ++i)
		if (deg[i] == 1) {
			rt = i;
			break ;
		}

	int o(rt), lt(0);
	for (int i = 1;i <= n; ++i) {
		vis[o] = 1;
		for (int j = 0;j < 3; ++j)
			for (int k = 0;k < 3; ++k)
				if (j != k)
					d[o][j][k] = d[lt][k][3 - j - k] + a[o][j];
		int siz = (int) b[o].size( );
		for (int j = 0;j < siz; ++j)
			if (!vis[b[o][j]]) {
				lt = o, o = b[o][j];
				break ;
			}
		pre[o] = lt;
	}

	LL ans(INF), ii, jj;
	for (int i = 0;i < 3; ++i)
		for (int j = 0;j < 3; ++j)
			if (i != j && ans > d[o][i][j])
				ans = d[o][i][j], ii = i, jj = j;
	printf("%lld\n", ans);
	to[o] = ii, to[pre[o]] = jj;
	for (o = pre[pre[o]]; o ; o = pre[o]) {
		to[o] = 3 - ii - jj;
		ii = jj, jj = to[o];
	}
	for (int i = 1;i <= n; ++i)
		printf("%d ", to[i] + 1);
	return 0;
}
