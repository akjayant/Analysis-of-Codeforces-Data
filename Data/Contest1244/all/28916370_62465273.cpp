#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main()
{
    int t; cin >> t;
    while (t--) {
        int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c, y = (b + d - 1) / d;
        if (x + y > k) cout << -1 << "\n";
        else cout << x << " " << k - x << "\n";
    }
}
