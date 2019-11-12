#include <bits/stdc++.h>
#include <stdio.h>
 
using namespace std;
 
#define int long long
 
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
int dp[105][105][105];
void solve() {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 0;
    for (int s = 1; s <= 300; ++s) {
        for (int a = 0; a <= 100; ++a) {
            for (int b = 0; b <= 100; ++b) {
                int c = s - a - b;
                if (c > 100 or c < 0)
                    continue;
                if (a >= 1 and b >= 2) dp[a][b][c] = max(dp[a][b][c], dp[a - 1][b - 2][c] + 3);
                if (b >= 1 and c >= 2) dp[a][b][c] = max(dp[a][b][c], dp[a][b - 1][c - 2] + 3);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << dp[a][b][c] << '\n';
    }
}       
