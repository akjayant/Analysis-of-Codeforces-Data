#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const ll MOD = 1e9+7;
ll dp[100005];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= 100000; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    string s; cin >> s;
    int n = s.length();
    s = "#" + s;
    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        int st = i;
        if (s[i] == 'm' || s[i] == 'w') ans = 0;
        while (s[i + 1] == s[st] && (s[i + 1] == 'n' || s[i + 1] == 'u')) i++;
        ans = (ans * dp[i - st + 1]) % MOD;
    }
    cout << ans << endl;
}
 