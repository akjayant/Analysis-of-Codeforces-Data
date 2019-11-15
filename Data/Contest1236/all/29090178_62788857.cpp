#include <cstdio>

const int INF = 1e9 + 7;
const long long INFLL = 1e18 + 7;

const int MOD = 1e9 + 7;

long long n, m, ans;

long long powmod(long long base, long long exp)
{
	long long res = 1;
	while (exp)
	{
		if (exp & 1) (res *= base) %= MOD;
		(base *= base) %= MOD;
		exp >>= 1;
	}
	return res;
}

int main()
{
	scanf("%lld%lld", &n, &m);
	printf("%lld\n",  powmod((powmod(2, m) - 1), n));
	return 0;
}
