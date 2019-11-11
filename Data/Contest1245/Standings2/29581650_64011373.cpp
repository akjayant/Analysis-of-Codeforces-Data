#include <iostream>
#include <queue>
#include <algorithm>
#include <random>
#include <vector>
#include <assert.h>
#include <set>
#include <unordered_set>
#include <numeric>
#include <map>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <bitset>
#include <sstream>

#pragma warning(disable : 4996)
using namespace std;

#define ft first
#define sd second
#define all(__array) (__array).begin(), (__array).end()
#define nl '\n'
#define mod(__val, __mod) ((((__val) % (__mod)) + (__mod)) % (__mod))
typedef long long ll;
typedef unsigned long long ull;
typedef double dl;	

const ll LINF = numeric_limits<ll>::max();
const int INF = numeric_limits<int>::max();
const double EPS = 1e-8;
const double PI = acos(-1);
random_device rnd;

const int MOD = (int)1e9 + 7;

inline void solve() {
	string s;
	cin >> s;
	if (count(all(s), 'w') + count(all(s), 'm') > 0) {
		cout << 0 << nl;
		return;
	}
	vector<int> dp(s.size() + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= (int)s.size(); i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	int ans = 1;
	vector<pair<int, bool>> lens;
	lens.push_back({ 1, false });
	for (int i = 1; i < (int)s.size(); i++) {
		if (s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u')) {
			lens.back().second = true;
			lens.back().first++;
		}
		else {
			lens.push_back({ 1, false });
		}
	}


	for (auto& i : lens) {
		if (!i.second) {
			continue;
		}
		ans = (ans * 1LL * dp[i.first]) % MOD;
	}
	cout << ans;

}

inline void IO() {
#ifdef _SEVA
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

int main() {
	IO();
	//int t;
	//cin >> t;
	//while (t--)
	solve();
	return 0;
}