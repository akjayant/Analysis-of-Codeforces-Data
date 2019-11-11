#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 1;
const int mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int n = (int)s.length();
	s = "?" + s;
	vector<ll> dp(n + 1, 0);
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i] == s[i - 1] and (s[i] == 'u' or s[i] == 'n')) {
			dp[i] = (dp[i] + dp[i - 2] + dp[i - 1]) % mod;
			continue;
		}
		dp[i] = (dp[i - 1] + dp[i]) % mod;
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'm' or s[i] == 'w') {
			dp[n] = 0;
		}
	}
	cout << dp[n] << endl;
	return 0;
}