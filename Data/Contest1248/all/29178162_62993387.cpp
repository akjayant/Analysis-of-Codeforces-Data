#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;

ll bin_pow(ll a, ll n, ll mod) {
	if (n == 0)return 1;
	if (n & 1) {
		return (a * bin_pow(a, n - 1, mod)) % mod;
	}
	else {
		ll tmp = bin_pow(a, n / 2, mod);
		return (tmp * tmp) % mod;
	}
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<ll> dp(1 + 2e5);
	dp[1] = 1;
	dp[0] = 1;
	for (int i = 2; i < 2e5; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}
	ll ans = 2ll * ((((dp[n] + dp[m]) % mod - 1) + mod)%mod);
	ans += mod;
	ans %= mod;
	cout << ans;
	return 0;
}