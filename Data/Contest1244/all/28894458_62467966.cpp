#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        double a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int tmp1 = ceil(a / c), tmp2 = ceil(b / d);
        if (tmp1 + tmp2 <= k) {
            cout << tmp1 << " " << tmp2 << endl;
        } else cout << "-1" << endl;
    }
    return 0;
}
