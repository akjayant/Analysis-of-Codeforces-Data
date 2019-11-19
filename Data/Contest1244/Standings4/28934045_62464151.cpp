#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int k;
        cin >> k;
        int x = (a + c - 1) / c, y = (b + d - 1) / d;
        if (x + y <= k) {
            cout << x << " " << y;
        } else {
            cout << -1;
        }
    cout << endl;


    }
}
