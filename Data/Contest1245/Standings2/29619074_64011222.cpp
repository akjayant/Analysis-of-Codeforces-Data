#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[100001];
string str;

#define MOD 1000000007

int doDp(int idx) {
	if (idx >= str.size() - 1) return 1;
	if (dp[idx] != -1) return dp[idx];
	if (str[idx] == 'n' && str[idx + 1] == 'n') {
		dp[idx] = (doDp(idx + 1) + doDp(idx + 2)) % MOD;
		return dp[idx];
	}
	if (str[idx] == 'u' && str[idx + 1] == 'u') {
		dp[idx] = (doDp(idx + 1) + doDp(idx + 2)) % MOD;
		return dp[idx];
	}
	dp[idx] = doDp(idx + 1);
	return dp[idx];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> str;

	bool pass = true;

	for (int i = 0; i <= str.size(); i++) {
		dp[i] = -1;
		if (str[i] == 'm' || str[i] == 'w') {
			pass = false;
			break;
		}
	}

	if (!pass) {
		cout << 0;
		return 0;
	}
	else {
		cout << doDp(0);
	}

	
}