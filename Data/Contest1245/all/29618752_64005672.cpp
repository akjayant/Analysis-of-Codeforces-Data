#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5 + 5;
const long long mod = 1e9 + 7;
long long dp[mn];

void pre() {
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < mn; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    pre();
    string s;
    cin >> s;

    long long ans = 1;

    for (int i = 0; i < s.length();) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout << "0";
            exit(0);
        } else if (s[i] == 'u' || s[i] == 'n') {
            int j = i + 1;
            while (s[j] == s[i])
                j++;
            ans = ans * dp[j - i] % mod;
            i = j;
        } else {
            i++;
        }
    }

    cout << ans;
}