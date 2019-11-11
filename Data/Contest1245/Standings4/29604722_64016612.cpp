#include "bits/stdc++.h"
#define N 100000
using namespace std;
const int MOD = 1e9 + 7;
int dp[N + 5][2];
char s[N + 5];
void prework() {
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= N; i++) dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD, dp[i][1] = dp[i - 1][0];
}
int main(int argc, char const *argv[]) {
	prework();
	scanf("%s", s);
	int n = strlen(s), cnt = 0, ans = 1;
	for (int i = 0; i < n; i++) { 
		if (s[i] == 'w' || s[i] == 'm') { puts("0"); return 0; }
		if (i && s[i] != s[i - 1]) {
			// printf("cnt = %d\n", cnt);
			if (s[i - 1] == 'u' || s[i - 1] == 'n') 
				ans = ans * 1ll * dp[cnt][0] % MOD;
			cnt = 0;
		} 
		cnt++;
	}
	if (s[n - 1] == 'u' || s[n - 1] == 'n') ans = ans * 1ll * dp[cnt][0] % MOD;
	printf("%d\n", ans);
	return 0;
}