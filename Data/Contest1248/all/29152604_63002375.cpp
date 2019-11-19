#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int dp[100005];

int main() {
	int n, m;
	cin >> n >> m;

	dp[0] = 1;
	dp[1] = 2;
	for (int i = 0; i < max(n, m); i++) {
		dp[i + 2] = (dp[i] + dp[i + 1]) % MOD;
	}

	unsigned long long res = dp[m - 1];

	cout << ((unsigned long long)(res + dp[n - 1] - 1) * 2) % MOD;
}