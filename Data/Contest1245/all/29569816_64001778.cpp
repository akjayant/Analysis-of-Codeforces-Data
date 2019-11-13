#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define clr(a, x) memset(a, x, sizeof(a))
#define pii pair<int, int>
#define pb push_back

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MOD = 1000000007;

ll fib[100015];
char s[100015];
int main() {
	scanf("%s", s + 1);
	int L = strlen(s + 1);
	fib[0] = fib[1] = 1;
	for (int i = 2; i <= L; ++i) {
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	}
	ll ans = 1;
	for (int i = 1; i <= L; ) {
		if ('w' == s[i] || 'm' == s[i]) ans = 0;
		int j = i;
		while (j <= L && s[j] == s[i]) ++j;
		if ('u' == s[i] || 'n' == s[i]) {
			ans = ans * fib[j - i] % MOD;
		}
		i = j;
	}
	printf("%lld\n", ans);
	return 0;
}
