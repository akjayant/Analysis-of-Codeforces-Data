#include <bits/stdc++.h>
#define int long long
#define TTT long long
#define all(x) x.begin(), x.end()
#define forn(n) for (int i = 0; i < n; i++)
#define cint [&](){TTT x; cin >> x; return x;}()
using namespace std;

const int N = 1e5 + 1;
void trymax(int& x, int y) {
    x = max(x, y);
}
void trymin(int& x, int y) {
    x = min(x, y);
}

signed main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                ans = max(ans, n + 1);
                ans = max(ans, 2 * (i + 1));
                ans = max(ans, (n - i) * 2);
            }
        }
        cout << ans << '\n';
    }


}
