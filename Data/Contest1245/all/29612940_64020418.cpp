#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define ff first
#define ss second
#define sz(vv) (int) vv.size()
#define all(a) a.begin(), a.end()
#define lb lower_bound
#define ub upper_bound
#define _ << " " <<

#define int ll

const int MOD = 1e9 + 7;

int dp[100100];

void solve() {
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i < 100100; ++i) {
        dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    }
    string s;
    cin >> s;
    s.push_back('z');
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0 << endl;
            return;
        }
    }
    int ans = 1;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'u') {
            x += 1;
        }
        if (s[i] != 'u') {
            ans *= dp[x];
            ans %= MOD;
            x = 0;
        }
    }
    x = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'n') {
            x += 1;
        }
        if (s[i] != 'n') {
            ans *= dp[x];
            ans %= MOD;
            x = 0;
        }
    }
    cout << ans << endl;
}

signed main() {
///#define TASK ""
#if !defined(LOCAL) && defined(TASK)
    freopen(TASK".in", "r", stdin);
    freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tests = 1;
    // cin >> tests;
    while (tests--) {
        solve();
    }
    return 0;
}

