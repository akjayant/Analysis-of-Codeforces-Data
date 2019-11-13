#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin >> k;
    for (int _ = 0; _ < k; ++_) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        if (s == t) {
            cout << "Yes\n";
            continue;
        }
        int cnt = 0;
        int ps1 = -1, ps2 = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                ++cnt;
                if (ps1 == -1) {
                    ps1 = i;
                } else
                    ps2 = i;
            }
        }
        if (cnt != 2) {
            cout << "No\n";
            continue;
        }
        if (t[ps2] == t[ps1] && s[ps2] == s[ps1]) {
            cout << "Yes\n";
            continue;
        }
        cout << "No\n";
    }
    return 0;
}
