//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define sqr(a) (a * a)
#define ll long long
#define ull unsigned long long
using namespace std;

#define mod 1000000007

int solve2(int n, int m) {

    if (n == 1) {
        return 2;
    }

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(2)));

    dp[0][0][1] = 1;
    dp[0][1][0] = 1;
    dp[1][1][1] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;
    dp[1][0][0] = 1;

    for (int i = 2; i < n; ++i) {
        dp[i][0][0] = (dp[i - 2][0][1] + dp[i - 2][1][1]) % mod;
        dp[i][1][1] = (dp[i - 2][1][0] + dp[i - 2][0][0]) % mod;
        dp[i][1][0] = (dp[i - 2][0][0] + dp[i - 2][0][1] + dp[i - 2][1][0]) % mod;
        dp[i][0][1] = (dp[i - 2][1][1] + dp[i - 2][1][0] + dp[i - 2][0][1]) % mod;
    }

    return (dp[n - 1][0][0] + dp[n - 1][0][1] + dp[n - 1][1][0] + dp[n - 1][1][1]) % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (solve2(n, m) + solve2(m, n) - 2) % mod << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}