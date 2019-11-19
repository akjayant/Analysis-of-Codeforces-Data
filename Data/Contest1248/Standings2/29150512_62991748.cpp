#include <bits/stdc++.h>

using namespace std;

const int Dim = 1e5 + 5;
const long long Mod = 1e9 + 7;

long long n, m;
long long dp[Dim];

int main() {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    cin >> n >> m;

    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= max (n, m); ++ i) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= Mod;
    }

    long long ans = 2 * (dp[n] + dp[m] - 1LL);
    ans %= Mod;

    cout << ans << '\n';
    return 0;
}
