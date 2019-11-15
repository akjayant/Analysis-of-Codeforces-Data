#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 1e5, M = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= M) a -= M;
    return a;
}

int dp[N], n;

string s;

void lol_anton() {
    cin >> s;
    n = s.size();
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'm' || s[i] == 'w') {
            cout << 0;
            exit(0);
        }
    }
    for (int i = 1; i < n; i++) {
        dp[i] = add(dp[i], dp[i - 1]);
        if (s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n')) {
            dp[i] = add(dp[i], (i - 2 < 0 ? 1 : dp[i - 2]));
        }
    }
    cout << dp[n - 1];
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lol_anton();
}