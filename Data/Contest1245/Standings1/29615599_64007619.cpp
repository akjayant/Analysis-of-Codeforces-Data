#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
string s;

int add(int a, int b) {
	return (a + b) % mod;
}

int mul(long long a, long long b) {
	return a*b%mod;
}

const int maxn = 1e5 + 10;
bool vis[maxn];
int memo[maxn];

int dp(int pos) {
	if (pos >= s.size()) return 1;
	if (vis[pos]) return memo[pos];
	vis[pos] = 1;
	if (s[pos] == 'm' or s[pos] == 'w') return memo[pos] = 0;
	if (s[pos] != 'u' and s[pos] != 'n') return memo[pos] = dp(pos+1);	
	int ans = dp(pos + 1);
	if (pos + 1 < s.size() and s[pos+1] == s[pos]) {
		ans = add(ans, dp(pos + 2));
	}
	return memo[pos] = ans;
}

int main() {
	cin >> s;
	cout << dp(0) << endl;
	return 0;
}