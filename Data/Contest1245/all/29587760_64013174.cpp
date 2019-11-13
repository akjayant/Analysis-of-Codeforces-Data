#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int t, n, a, b, c, x;
string s;

const int mod = 1e9 + 7;


int dp[100005];



int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;

	for (auto c : s) {
		if (c == 'w' || c == 'm') {
			cout << 0 << endl;
			return 0;
		}
	}


	dp[0] = dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 100005; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}



	vector<int> v;
	int cur = 0;
	if (s[0] == 'u' || s[0] == 'n') cur++;

	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == 'u' || s[i] == 'n') {
			if (s[i] == s[i - 1]) {
				cur ++;
				continue;
			}
			v.push_back(cur);
			cur = 1;
		} else {
			v.push_back(cur);
			cur = 0;
		}
	}
	v.push_back(cur);

	long long ans = 1;

	for (auto x : v) {
		ans = (ans * dp[x]) % mod;
	}
	cout << ans << endl;

	
	return 0;
}