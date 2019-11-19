#include <bits/stdc++.h>
#define MAX (100000 + 7)
using std::sort;

int N, a[MAX];
long long sum, sum0;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i), sum += a[i];
	sort(a + 1, a + N + 1);
	for (int i = 1; i <= (N >> 1); i++)
		sum0 += a[i];
	printf("%lld\n", sum0*sum0 + (sum-sum0)*(sum-sum0));
}