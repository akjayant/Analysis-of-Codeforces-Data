# include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int dp[100005];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << 0 << endl;
            return 0;
        }
    }
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % mod;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'u' || s[i] == 'n') {
            int pt = i, cn = 1;
            while (pt + 1 < n && s[pt + 1] == s[i])
                pt ++, cn ++;
            ans = (ans * 1ll * dp[cn]) % mod;
            i = pt;
        }
    }
    cout << ans << endl;
}
