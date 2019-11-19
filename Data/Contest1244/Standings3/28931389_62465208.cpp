#include <bits/stdc++.h>
//#define int long long

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    for (int q = 0; q < n; ++q) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (c + a - 1) / c;
        int y = (d + b - 1) / d;
        if (x + y <= k)
            cout << x << " " << y << "\n";
        else
            cout << "-1\n";
    }
}
