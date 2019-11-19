#include <bits/stdc++.h>

using namespace std;

typedef double de;
typedef long long int LL;
const int N = 100100;

LL a[N], b[N];

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);

	for (; T -- ;) {
		int n, m, inv;
		scanf("%d", &n);

		a[0] = a[1] = 0;
		for (int i = 1;i <= n; ++i)
			scanf("%d", &inv), a[inv & 1] ++;

		scanf("%d", &m);
		b[0] = b[1] = 0;
		for (int i = 1;i <= m; ++i)
			scanf("%d", &inv), b[inv & 1] ++;

		printf("%lld\n", a[0] * b[0] + a[1] * b[1]);
	}

	return 0;
}
