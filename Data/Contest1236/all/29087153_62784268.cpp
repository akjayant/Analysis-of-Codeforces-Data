#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 500005;

signed main() {
    int a, b, c, d, e, f, g, h, n, m, i, j, k;
    int x, y, t, q, l, r, p, z;
    string s = "";

    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int ans = 0;
        for (int i = 0; i < 100; i++) {
            if (a >= i && b >= 2 * i) {
                int cur = 3 * i;
                d = min(b - 2 * i, c / 2);
                cur += 3 * d;
                ans = max(ans, cur);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
