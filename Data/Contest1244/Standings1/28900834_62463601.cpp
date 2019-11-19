#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
    int t;
    cin >> t;
    while (t) {
        --t;
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if (k < (a + c - 1) / c + (b + d - 1) / d) cout << -1 << '\n';
        else cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
