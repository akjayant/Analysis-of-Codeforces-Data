#include <bits/stdc++.h>

using namespace std;

typedef double de;
typedef long long int LL;
const int N = 100100;
const LL mo = 1e9 + 7;

LL d[N][2];

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);

	d[1][0] = 1;
	for (int i = 2;i <= max( n, m ); ++i) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1]) % mo;
		d[i][1] = d[i - 1][0];
	}

	printf("%lld", (1ll * (2 * (d[n][0] + d[n][1]) + 2 * (d[m][0] + d[m][1]) - 2 + mo)) % mo);
	return 0;
}
