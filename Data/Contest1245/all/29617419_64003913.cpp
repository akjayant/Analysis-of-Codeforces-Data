#include <bits/stdc++.h>
using i64 = long long;

int main() {
    constexpr i64 mod = 1000000007;
    std::string s;
    std::cin >> s;
    int n = s.size();
    s += '$';
    std::vector<i64> dp(s.size() + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            std::cout << 0 << std::endl;
            return 0;
        }
        if (s[i] == 'u' && s[i + 1] == 'u') {
            dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
        } else if (s[i] == 'n' && s[i + 1] == 'n') {
            dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
        }
        dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
    }
    std::cout << dp[n] << std::endl;

    return 0;
}
