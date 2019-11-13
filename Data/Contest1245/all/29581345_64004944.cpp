#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")

#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
// #define int long long


using namespace std;
typedef vector <int> vi;
typedef pair<int,int> pii;
const int MOD = 1e9 + 7;

inline void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}


void solve() {
	string s; cin >> s;
	int n = s.size();
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'm' || s[i] == 'w') {
			cout << "0\n";
			return;
		}
	}
	vector <int> dp(n, 1);
	// for(auto i : dp) cout << i << " "; cout << "\n";
	for(int i = 1; i < n; ++i) {
		if(s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n') ) {
			dp[i] = dp[i-1];
			if(i - 2 >= 0) dp[i] += dp[i-2]; else dp[i] += 1;
			if(dp[i] >= MOD) dp[i] -= MOD;
		} else {
			dp[i] = dp[i-1];
		}
	}
	// for(auto i : dp) cout << i << " "; cout << "\n";
	cout << dp[n-1] << "\n";
}


// #define lolipop

signed main() {
#ifdef lolipop
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	fastio();
	solve();

}