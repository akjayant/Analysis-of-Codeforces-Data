#include <bits/stdc++.h>

using namespace std;

int check(string s) {
    int res = 0;
    int cur = 0;
    int n = (int) s.size();
    int pos = -1;
    vector <int> lst(n, -1);
    for (int i = 0; i < n; i++) {
        lst[i] = pos + 1;
        if (s[i] == '1') {
            pos = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cur++;
        } else {
            cur += 2;
            res = max(res, cur + (i - lst[i]));
        }
        res = max(res, cur);
    }
    int last_pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            last_pos = i;
        }
    }
    if (last_pos != -1) {
        res = max(res, (last_pos + 1) * 2);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    ans = check(s);
    reverse(s.begin(), s.end());
    ans = max(ans, check(s));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
