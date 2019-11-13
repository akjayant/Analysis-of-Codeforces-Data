#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)

void solve();

signed main () {
    cout.precision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
    int t = 1; 
    // cin >> t;
    int tt = t;
    while (t--) { 
        solve();
    }
    return 0;
}
const int N = 1e5 + 55;
int dp[N];
const int M = 1e9 + 7;
void solve() {
    string s;
    cin >> s;
    int n = (int) s.size();
    for (auto i : s) {
    	if (i == 'm' or i == 'w') {
    		cout << 0;
    		return;
    	}
    }
    s = '$' + s;
    dp[1] = 1;
    dp[0] = 1;
    for (int i = 2; i <= n; ++i) {
    	if (s[i] != 'n' and s[i] != 'u') {
    		dp[i] = dp[i - 1];
    	}
    	else if (s[i] == 'n') {
    		if (s[i - 1] == 'n') {
    			dp[i] = dp[i - 1] + dp[i - 2];
    		}
    		else {
    			dp[i] = dp[i - 1];
    		}
    	}
    	else if (s[i] == 'u') {
    		if (s[i - 1] == 'u') {
    			dp[i] = dp[i - 1] + dp[i - 2];
    		}
    		else {
    			dp[i] = dp[i - 1];
    		}
    	}
    	dp[i] %= M;
    }
    cout << dp[n];
}       
