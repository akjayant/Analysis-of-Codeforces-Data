#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

const int N = 1e5 + 100;
const int MOD = 1e9 + 7;

int n;
char str[N];
ll res[N], dp[N];

void add(ll &a, ll b) {
	a = (a + b) % MOD;
}

int main() {
	dp[0] = dp[1] = 1;
	for (int i = 2; i < N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}
	scanf("%s", str);
	n = strlen(str);
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'w' || str[i] == 'm') ans = 0;	
		if (str[i] == 'u') {
			int cnt = 1;
			while (i + 1 < n && str[i + 1] == 'u') {
				i++;
				cnt++;
			}
			ans = ans * dp[cnt] % MOD;
		}
		if (str[i] == 'n') {
			int cnt = 1;
			while (i + 1 < n && str[i + 1] == 'n') {
				i++;
				cnt++;
			}
			 ans = ans * dp[cnt] % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}