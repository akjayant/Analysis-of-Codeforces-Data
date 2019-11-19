#include <bits/stdc++.h>
#define MAX (100000 + 7)
#define mod 1000000007ll
using std::max;

int N, M;
long long ans, f[MAX];

int main()
{
	scanf("%d%d", &N, &M), f[0] = f[1] = 1;
	for (int i = 1; i <= max(N, M); i++)
		f[i] = (f[i-1] + f[i-2]) % mod;
	printf("%lld\n", (f[M] + f[N] - 1)% mod * 2 % mod);
}