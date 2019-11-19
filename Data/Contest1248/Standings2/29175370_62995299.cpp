#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

bool MULTI_TEST = false;

const int MOD = 1e9 + 7;
const int MAXN = 1e5;

int bpow(int n, int k) {
    if (k == 0) {
        return 1;
    }
    int t = bpow(n, k / 2);
    if (k % 2 == 0) {
        return t * t % MOD;
    }
    return t * t % MOD * n % MOD;
}

int dp[MAXN + 1][2][2][2];
int cnt[MAXN + 1][2];

void solve() {
    int n, m;
    cin >> n >> m;
    dp[1][0][0][0] = 1;
    dp[1][1][0][0] = 1;
    for (int i = 2; i <= MAXN; i++) {
        dp[i][0][0][0] = dp[i - 1][1][0][0];
        dp[i][0][1][1] = dp[i - 1][0][0][0] + dp[i - 1][0][0][1];
        dp[i][0][0][1] = (dp[i - 1][1][0][1] + dp[i - 1][1][1][1]) % MOD;

        dp[i][1][0][0] = dp[i - 1][0][0][0];
        dp[i][1][1][1] = dp[i - 1][1][0][0] + dp[i - 1][1][0][1];
        dp[i][1][0][1] = (dp[i - 1][0][0][1] + dp[i - 1][0][1][1]) % MOD;
    }

    for (int i = 1; i <= MAXN; i++) {
        cnt[i][0] = (dp[i][0][0][0] + dp[i][1][0][0]) % MOD;
        cnt[i][1] = (dp[i][0][1][1] + dp[i][0][0][1] + dp[i][1][1][1] + dp[i][1][0][1]) % MOD;
    }
   
    cout << (cnt[m][0] + cnt[m][1] + cnt[n][1]) % MOD;
}

signed main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    if (MULTI_TEST) {
        cin >> t;
    }
    for (int i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
