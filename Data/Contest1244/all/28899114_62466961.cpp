#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans = max(ans, (i + 1) * 2);
            ans = max(ans, i + 1 + n - i);
            ans = max(ans, (n - i) * 2);
        }
    }
    cout << ans << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
