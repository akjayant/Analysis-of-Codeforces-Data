#include<cstdio>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
long long mod = 1e9 + 7;

int n, m;
long long dp[100001];
long long dp00[100001];
long long dp01[100001];
long long dp10[100001];
long long dp11[100001];

long long solve() {
	dp[1] = 1; dp[2] = 2;
	dp10[2] = dp11[2] = 1;
	for (int i = 3; i <= max(n,m); ++i) {
		dp00[i] = dp10[i - 1];
		dp01[i] = (dp00[i - 1] + dp10[i - 1]) % mod;
		dp10[i] = (dp01[i - 1] + dp11[i - 1]) % mod;
		dp11[i] = dp01[i - 1];
		dp[i] = (dp00[i] + dp01[i] + dp10[i] + dp11[i]) % mod;
	}
	return (dp[n] - 1 + dp[m]) * 2 % mod;
}

int main() {
	scanf("%d%d", &n, &m);

	long long ans = solve();
	printf("%I64d", ans);
}