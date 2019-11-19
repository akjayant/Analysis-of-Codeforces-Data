#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ans1 = (a + c - 1) / c;
        int ans2 = (b + d - 1) / d;
        if (ans1 + ans2 > k)
            cout << -1 << '\n';
        else
            cout << ans1 << " " << ans2 << '\n';
    }
    return 0;
}