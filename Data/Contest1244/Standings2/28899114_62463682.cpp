#include <bits/stdc++.h>
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#define int long long

using namespace std;

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = (a + c - 1) / c;
    int y = (b + d - 1) / d;
    if (x + y > k) {
        cout << "-1\n";
        return;
    }
    cout << x << " " << y << "\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
