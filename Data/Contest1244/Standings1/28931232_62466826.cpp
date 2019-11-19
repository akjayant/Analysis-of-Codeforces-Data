#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int ans = n;
    rep(i, 0, n) {
        if (s[i] == '1') {
            int cur = max(2 * (i + 1), 2 * (n - i));
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
}

main() {
    int t;
    cin >> t;
    while (t--) {
        solve();

    }
}