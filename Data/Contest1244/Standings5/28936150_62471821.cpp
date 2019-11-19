#include <bits/stdc++.h>

#define int long long
typedef long long ll;
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for (int i = 0; i < s.size(); i++) {
            int x = i, y = n - i - 1;
            if (s[i] == '1')ans = max(ans, max(2 * x, 2 * y) + 2);
        }
        cout << ans << endl;
    }
}