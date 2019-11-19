#include <cstdio>
using namespace std;
const int MOD = 1000000007;

int n, m, dp[100001];

int main() {
	scanf("%d%d", &n, &m);
	dp[0] = dp[1] = 2;
	for (int i=2; i<=100000; ++i) {
		dp[i] = (dp[i-1] + dp[i-2]) % MOD;
	}
	printf("%d\n", ((dp[n] + dp[m]) % MOD + MOD-2) % MOD);
	return 0;
}