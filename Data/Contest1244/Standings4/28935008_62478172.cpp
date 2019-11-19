#include <bits/stdc++.h>

const int N = 1005;

char s[N];
int dp[3][N], n;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			dp[1][i] = std::max(dp[1][i], dp[1][i - 1] + 1);
			dp[2][i] = std::max(dp[1][i], dp[2][i - 1] + 1);
			if (s[i] == '1') {
				dp[1][i] = std::max(dp[1][i], dp[2][i - 1] + 2);
				dp[2][i] = std::max(dp[2][i], dp[1][i - 1] + 2);
			}
		}
		int hd = n + 1, tl = -1;
		for (int i = 1; i <= n; i++)
			if (s[i] == '1') { hd = i; break; }
		for (int i = n; i >= 1; i--)
			if (s[i] == '1') { tl = i; break; }
		int tmp = std::max(tl * 2, (n - hd + 1) * 2), ans = std::max(dp[1][n], dp[2][n]);
		printf("%d\n", std::max(tmp, ans));
	}
	return 0;
}
