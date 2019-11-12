#include "bits/stdc++.h"
#define N 100
using namespace std;
bool vis[N + 5][N + 5][N + 5];
int dp[N + 5][N + 5][N + 5];
int solve(int a, int b, int c) {
	if (vis[a][b][c]) return dp[a][b][c];
	dp[a][b][c] = 0;
	vis[a][b][c] = 1;
	if (a >= 1 && b >= 2) dp[a][b][c] = max(solve(a - 1, b - 2, c) + 3, dp[a][b][c]);
	if (b >= 1 && c >= 2) dp[a][b][c] = max(solve(a, b - 1, c - 2) + 3, dp[a][b][c]);
	// printf("a = %d b = %d c = %d dp = %d\n", a, b, c, dp[a][b][c]);
	return dp[a][b][c];
}
void work() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", solve(a, b, c));
}
int main(int argc, char const *argv[]) {
	int T;
	scanf("%d", &T);
	while (T--) work();
	return 0;
}