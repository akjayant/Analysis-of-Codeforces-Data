#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (c * i >= a && j * d >= b && i + j <= k) {
                cout << i << " " << j << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
    return;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}