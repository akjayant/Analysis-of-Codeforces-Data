#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, a, b, c, d, k;
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c, y = (b + d - 1) / d;
        if (x + y > k) cout << -1 << endl;
        else cout << x << " " << y << endl;
    }
    return 0;
}