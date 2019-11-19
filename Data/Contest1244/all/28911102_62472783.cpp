// qdd on Oct 13, 2019

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n + count(s.begin(), s.end(), '1');
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ans = max(ans, 2 * max(n - i, i + 1));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}