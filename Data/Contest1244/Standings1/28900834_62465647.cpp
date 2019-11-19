#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int t;
    cin >> t;
    while (t) {
        --t;
        int n;
        string s;
        cin >> n >> s;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ans = max(ans, 2 * (i + 1));
                ans = max(ans, 2 * (n - i));
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
