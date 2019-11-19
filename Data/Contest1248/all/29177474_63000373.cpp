#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

#define rep(i,a) for (int i = 0; i < (a); ++i)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
const ll mod = 1000000007;
ll dp[100100][3][3];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	dp[1][1][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 2; i <= 100000; ++i) {
		dp[i][1][0] = dp[i - 1][0][1] + dp[i - 1][0][2];
		dp[i][2][0] = dp[i - 1][1][0];

		dp[i][0][1] = dp[i - 1][1][0] + dp[i - 1][2][0];
		dp[i][0][2] = dp[i - 1][0][1];

		dp[i][1][0] %= mod;
		dp[i][2][0] %= mod;
		dp[i][0][1] %= mod;
		dp[i][0][2] %= mod;
	}

	ll n, m; cin >> n >> m;
	ll tmp = dp[n][1][0] + dp[n][2][0] + dp[n][0][1] + dp[n][0][2];
	tmp %= mod;

	ll tmp2 = dp[m][1][0] + dp[m][2][0] + dp[m][0][1] + dp[m][0][2];
	tmp2 %= mod;

	
	ll tmp3 = tmp - 2;	// ���ӵȰ��� ������ ���Ѵ�.
	ll sol = (tmp3 + tmp2) % mod;
	cout << sol;
	return 0;
}