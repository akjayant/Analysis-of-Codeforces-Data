#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mkp make_pair
#define sqr(s) ((s) * (s))

using namespace std;

typedef complex<int> point;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;

void solve() {
	string str;
	cin >> str;
	if (count(ALL(str), 'm') > 0 || count(ALL(str), 'w') > 0) {
		cout << 0 << endl;
		return;
	}
	int n = sz(str);
	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (str[i - 1] == 'u' && str[i - 2] == 'u')
			dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		else if (str[i - 1] == 'n' && str[i - 2] == 'n')
			dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
		else
			dp[i] = dp[i - 1];
	}
	cout << dp[n] << endl;
}	

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	// freopen("input.txt", "r", stdin);
	int t = 1;
	// cin >> t;
	while (t--)
		solve();
}
