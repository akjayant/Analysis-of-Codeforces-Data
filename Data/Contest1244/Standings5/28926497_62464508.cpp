#include <bits/stdc++.h>

using namespace std;

typedef double de;
typedef long long int LL;
const int N = 100100;

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);

	for (; T -- ;) {
		int a, b, c, d, k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int tmp1((a - 1) / c + 1);
		int tmp2((b - 1) / d + 1);
		if (tmp1 + tmp2 <= k)
			printf("%d %d\n", tmp1, tmp2);
		else
			printf("-1\n");
	}

	return 0;
}
