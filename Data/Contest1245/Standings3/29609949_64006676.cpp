#include <bits/stdc++.h>
using namespace std;
long long dp[1000111];
const int MOD = 1e9+7;
bool basaur = false;
int main()
{
	int n;
	string s;
	cin >> s;
	dp[1] = 1;
	dp[0] = 1;
	int in = 2;
	int len = s.size();
	for (auto i : s) {
		if (i == 'w' || i == 'm') basaur = true;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n')) {
			dp[i+1] = dp[i] + dp[i-1];
		}
		else dp[i+1] = dp[i];
		if (dp[i+1] > MOD) dp[i+1] %= MOD;
	}
	if (basaur) printf("0\n");
	else printf("%lld\n", dp[len]);
	return 0;
}