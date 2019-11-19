#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        string s;
        cin >> n >> s;
        int mn = n;
        for (int j = 0; j < n; ++j) {
            if (s[j] == '1') {
                mn = min(mn, min(j, n - 1 - j));
            }
        }
        cout << max(n, 2 * (n - mn)) << '\n';
    }
    return 0;
}