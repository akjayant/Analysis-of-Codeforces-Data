#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int tk = k;
    string s;
    cin >> s;
    vector <bool> col(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[(i + 1) % n] || s[i] == s[(i - 1 + n) % n]) col[i] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (!col[i]) ++cnt;
    queue <int> u, d;
    for (int i = 0; i < n; ++i) {
        //cout << i << ' ';
        if (!col[i] && col[(i + 1) % n]) u.push(i);
        else if (!col[i] && col[(i - 1 + n) % n]) {
            d.push(i);
            //cout << 1;
        }
        //cout << '\n';
    }
    vector <char> ans(n, 'E');
    for (int i = 0; i < n; ++i) if (col[i]) ans[i] = s[i];
    while (k) {
        int us = u.size(), ds = d.size();
        //cout << us << ' ' << ds << '\n';
        if (us + ds == 0) {
            break;
        }
        for (int i = 0; i < us; ++i) {
            int id = u.front();
            u.pop();
            if (!col[id]) ans[id] = ans[(id + 1) % n];
            //--cnt;
            col[id] = 1;
            if (!col[(id - 1 + n) % n]) {
                u.push((id - 1 + n) % n);
                //++cnt;
            }
        }
        for (int i = 0; i < ds; ++i) {
            int id = d.front();
            d.pop();
            if (!col[id]) ans[id] = ans[(id - 1 + n) % n];
            col[id] = 1;
            //--cnt;
            if (!col[(id + 1) % n]) {
                d.push((id + 1) % n);
                //++cnt;
            }
        }
        --k;
        /*for (int i = 0; i < n; ++i) cout << ans[i];
        cout << '\n';*/
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] != 'E') cout << ans[i];
        else {
            if (s[i] == 'W' && tk % 2) cout << 'B';
            if (s[i] == 'W' && (tk % 2) == 0) cout << 'W';
            if (s[i] == 'B' && tk % 2) cout << 'W';
            if (s[i] == 'B' && (tk % 2) == 0) cout << 'B';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
