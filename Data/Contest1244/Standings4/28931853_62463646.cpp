#include <bits/stdc++.h>

using namespace std;

main() {
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int k1 = (a + c - 1) / c;
        int k2 = (b + d - 1)/ d;
        if (k1 + k2 <= k) cout << k1 << ' ' << k2 << '\n';
        else cout << -1 << '\n';
    }
}
