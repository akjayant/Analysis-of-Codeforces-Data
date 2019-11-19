#include <bits/stdc++.h>

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int k = 0, mn = -1, mx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') mx = i;
            if (s[i] == '1' && mn == -1) mn = i;
        }
        if (mn == -1) {
            cout << n << '\n';
            continue;
        }
        if (mn == mx) {
            cout << max(2 * (mn + 1), 2 * (n - mn)) << '\n';
        } else {
            int ans = 0;
            ans = max(ans, mn + 1 + mx - mn + 1 + n - mx);
            ans = max(ans, 2 * (mn + 1));
            ans = max(ans, 2 * (mx + 1));
            ans = max(ans, mn + 1 + mx - mn + 1 + mx - mn);
            ans = max(ans, (n - mn) * 2);
            ans = max(ans, 2 * (n - mx));
            ans = max(ans, mn + 1 + n - mn);
            ans = max(ans, n + 1);
            cout << ans << '\n';
        }
    }
}
