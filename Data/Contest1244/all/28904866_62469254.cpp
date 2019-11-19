#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        if (s[0] == '1' || s[n - 1] == '1') {
            cout << 2 * n << endl;
        } else {
            int cnt = 0;
            for (char ch : s) cnt += ch - '0';
            int mx = 0;
            for (int i = 0; i < n; i++) if (s[i] == '1') {
                mx = max(mx, 2 * max(i + 1, n - i));
            }
            cout << max(mx, cnt + n) << endl;
        }
    }
    return 0;
}