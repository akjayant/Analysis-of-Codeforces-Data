#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c, y = (b + d - 1) / d;
        if (x + y <= k) {
            cout << x << " " << y << endl;
        } else {
            cout << -1 << endl;
        }
    }
}