#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;

int n;
long long f[MAX_N], ans = 1;
char s[MAX_N];

int main()
{
	f[0] = f[1] = 1;
	for (int i = 2; i < MAX_N; ++i)
		f[i] = (f[i - 1] + f[i - 2]) % MOD;
	scanf("%s", s); n = strlen(s);
	for (int i = 0, c = 0; i <= n; ++i)
		if (s[i] == 'm' || s[i] == 'w')
		{
			printf("0\n");
			return 0;
		}
		else if (s[i] == 'u' || s[i] == 'n')
		{
			if (i > 0 && s[i] != s[i - 1])
			{
				ans = ans * f[c] % MOD;
				c = 0;
			}
			++c;
		}
		else
		{
			ans = ans * f[c] % MOD;
			c = 0;
		}
	printf("%lld\n", ans);
	return 0;
}
