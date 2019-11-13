#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	s += '-';
	ll ans = 1;
	char prv = '-';
	int cnt = 0;
	ll dp[100001];
	dp[0] = dp[1] = 1;
	const ll MOD = 1000000007;
	for (int i = 2; i <= 100001; ++i) {
		dp[i] = dp[i - 2] + dp[i - 1];
		dp[i] %= MOD;
	}
	for (char c: s) {
		if (c == prv) {
			cnt++;
		} else {
			if (prv == 'w' || prv == 'm') ans = 0;
			if (prv == 'n' || prv == 'u') {
				ans *= dp[cnt];
				ans %= MOD;
			}
			prv = c;
			cnt = 1;
		}
	} 
	cout << ans << endl;
}