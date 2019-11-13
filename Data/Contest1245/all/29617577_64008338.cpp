#include <bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long


signed main() {
    fastio
    string s;
    cin >> s;
    char last = s[0];
    int cnt = 1;
    int ans = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) ++cnt;
        else {
            if (last == 'u' || last == 'n') {
                vector<int> dp (cnt + 1);
                dp[0] = 1;
                dp[1] = 1;
                for (int j = 2; j <= cnt; ++j) {
                    dp[j] = dp[j - 1];
                    dp[j] += dp[j - 2];
                    dp[j] %= (1000000007);
                }
                ans *= dp[cnt];
                ans %= 1000000007;
            } else if (last == 'm') {
                ans = 0;
                break;
            }
            else if (last == 'w') {
                ans = 0;
                break;
            }
            last = s[i];
            cnt = 1;
        }
    }
    if (last == 'u' || last == 'n') {
        vector<int> dp (cnt + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int j = 2; j <= cnt; ++j) {
            dp[j] = dp[j - 1];
            dp[j] += dp[j - 2];
            dp[j] %= (1000000007);
        }
        ans *= dp[cnt];
        ans %= 1000000007;
    }
    cout << ans;
}