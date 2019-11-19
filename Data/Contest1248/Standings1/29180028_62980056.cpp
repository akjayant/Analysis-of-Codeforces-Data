#include <bits/stdc++.h>

using namespace std;

typedef double de;
typedef long long int LL;
const int N = 100100;

LL a[N];

bool cmp ( LL ca, LL cb ) {
	return ca > cb;
}

int main ( ) {
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);

	for (int i = 1;i <= n; ++i)
		scanf("%lld", &a[i]);
	sort( a + 1, a + n + 1, cmp );

	LL sum1(0), sum2(0);
	for (int i = 1;i <= (n + 1) / 2; ++i)
		sum1 += a[i];
	for (int i = (n + 1) / 2 + 1;i <= n; ++i)
		sum2 += a[i];
	printf("%lld", sum1 * sum1 + sum2 * sum2);
	return 0;
}
