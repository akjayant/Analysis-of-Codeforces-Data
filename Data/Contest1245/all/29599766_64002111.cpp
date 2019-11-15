#include <bits/stdc++.h>

using namespace std;

int fib[200001];

const int mod = (int )(1e9) + 7;
char str[200001];
int ans = 1;
int main( ) {
	scanf("%s", str + 1);
	int n = (int )strlen(str + 1);
	for (int i = 1; i <= n; i ++)
		if (str[i] == 'm' || str[i] == 'w') ans = 0;
	fib[1] = 1;
	fib[2] = 2;
	for (int i = 3; i <= n; i ++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % mod;

	for (int i = 1; i <= n; i ++) {
		if (str[i] != 'u' && str[i] != 'n') continue;
		int tmp = i;
		while (tmp <= n && str[tmp] == str[i]) ++ tmp;
		-- tmp;
		int sz = tmp - i + 1;
		if (sz >= 2) {
			ans = 1LL * ans * fib[sz] % mod;
			ans %= mod;
		}
		i = tmp;
	}
	printf("%d\n", ans);
	return 0;
}
