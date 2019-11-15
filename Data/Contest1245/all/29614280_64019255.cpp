#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cassert>
using namespace std;

typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
constexpr int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
const long long mod = 1e9 + 7;
long long qpow(long long a, long long b) {
	long long res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
	}
	return res;
}
long long dp[maxn];
int main() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	dp[5] = 8;
	dp[6] = 13;
	for (int i = 7; i < maxn; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str;
	cin >> str;
	str.push_back('-');
	int rep = 1;
	vector<int>repss;
	long long ans = 1;
	if (str[0] == 'm' || str[0] == 'w') {
		ans = 0;
	}
	else for (int i = 1; i < str.size(); i++) {
		if (str[i] == 'm' || str[i] == 'w') {
			repss.clear();
			ans = 0;
			break;
		}
		if (str[i] == str[i - 1]) rep++;
		else {
			if (rep > 1 && str[i - 1] == 'u' || str[i - 1] == 'n') {
				ans = ans * dp[rep] % mod;
			}
			rep = 1;
		}
	}
	cout << ans;
	return 0;
}