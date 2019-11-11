#include <bits/stdc++.h>

using namespace std;

constexpr int MOD = 1'000'000'007;
long long ans = 1;
long long dp[100001];
void f(int k) {
    if(k <= 1)
        return;

    ans = ans * dp[k] % MOD;    
}

void solve() {
    string s;
    cin >> s;

    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    for(auto i = 3; i <= 100000; ++i)
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;

    auto n = 0, u = 0;
    for(auto c : s) {
        if(c == 'm' || c == 'w') {
            cout << 0 << endl;
            return;
        }
        else if(c == 'n') {
            n++;
            f(u);
            u = 0;
        }
        else if(c == 'u') {
            u++;
            f(n);
            n = 0;
        }
        else {
            f(n), f(u);
            n = 0, u = 0;
        }
    }

    f(n), f(u);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}