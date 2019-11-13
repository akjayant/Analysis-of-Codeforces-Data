#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1000000007;
constexpr int N = 100000;

char s[N + 3];
long long dp[N + 3];

long long solve(int n) {
	if (n <= 1) {
		return 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	return dp[n] = (solve(n - 1) + solve(n - 2)) % MOD;
}

int main() {
	long long ans;
	int n, i, j;

	memset(dp, -1, sizeof(dp));
	
	scanf("%s%n", s + 1, &n);

	ans = 1;

	for (i = 1; i <= n;) {
		if (s[i] == 'm' or s[i] == 'w') {
			printf("0\n");
			return 0;
		}

		if (s[i] == 'n' or s[i] == 'u') {
			for (j = i + 1; j <= n; j++) {
				if (s[j] != s[i]) {
					break;
				}
			}

			// [i, j - 1]
			ans = (ans * solve(j - i)) % MOD;
			i = j;
		}
		else {
			i++;
		}
	}

	printf("%lld\n", ans);
	
	return 0;
}
