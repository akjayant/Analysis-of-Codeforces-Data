#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

mt19937 gen((uint) chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 100;
const int MOD = 1000 * 1000 * 1000 + 7;

int dp[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	s = "#" + s;
	dp[0] = 1;

	for (int i = 1; i < s.size(); i++) {
		if (s[i] == 'm' || s[i] == 'w') {
			dp[i] = 0;
			continue;
		}

		if (s[i] == 'u' || s[i] == 'n') {
			dp[i] = dp[i - 1];

			if (i > 0 && s[i - 1] == s[i]) {
				dp[i] = (dp[i] + dp[i - 2]) % MOD;
			}
		} else {
			dp[i] = dp[i - 1];
		}
	}

	cout << dp[s.size() - 1];

	return 0;
}