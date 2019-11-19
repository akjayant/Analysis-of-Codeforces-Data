#include <bits/stdc++.h>

using namespace std;
const int inf = 1e9 + 7;
const int MAXN = 1e5 + 7;

int main() {
    cout.precision(20);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int cnt = (a + c - 1) / c + (b + d - 1) / d;
        if (cnt > k) {
            cout << -1 << endl;
        } else {
            cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << endl;
        }
    }
    return 0;
}