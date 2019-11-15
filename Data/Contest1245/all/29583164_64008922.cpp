#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll MOD = (ll)(1e9 + 7);

    string s;
    cin >> s;
    int n = s.size();

    ll res = 1;

    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    int len = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] != 'u') {
            res = (res * dp[len]) % MOD;
            len = 0;
            continue;
        }
        ++len;
    }
    res = (res * dp[len]) % MOD;
    len = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'n') {
            res = (res * dp[len]) % MOD;
            len = 0;
            continue;
        }
        ++len;
    }
    res = (res * dp[len]) % MOD;
    len = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            return 0;
        }
    }

    cout << res << endl;
    return 0;
}