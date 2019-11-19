#include <bits/stdc++.h>

using namespace std;

typedef double de;
typedef long long int LL;
const int N = 100100;

int a[N];

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);

	for (; T -- ;) {
		int n;
		scanf("%d", &n);

		int fr(-1), ed(-1);
		for (int i = 1;i <= n; ++i) {
			scanf("%1d", &a[i]);
			if (fr < 0 && a[i])
				fr = i;
			if (a[i])
				ed = i;
		}
		if (fr < 0)
			printf("%d\n", n);
		else if (fr == ed)
			printf("%d\n", max( n, 2 * max( fr, n - fr + 1 ) ));
		else {
			int ans = max( 2 * max( fr, n - fr + 1 ), 2 * max( ed, n - ed + 1 ) );
			printf("%d\n", max( ans, max( fr + max( ed, n - ed + 1 ), n - fr + 1 + max( ed, n - ed + 1 ) ) ));
		}
	}

	return 0;
}
