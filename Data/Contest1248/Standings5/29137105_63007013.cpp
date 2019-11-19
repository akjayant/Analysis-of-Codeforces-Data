#include "bits/stdc++.h"

using namespace std;

typedef long double db;
typedef long long ll;
typedef pair<db, db> pd;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define mod 1000000007
#define maxn 100005

ll n, m, k, q, a[maxn];
ll dp[maxn];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < maxn; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << (((2 * (dp[n] + dp[m]) % mod) % mod) - 2 + mod) % mod;

	return 0;
}
